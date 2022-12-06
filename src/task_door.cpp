/** @file task_door.cpp
 *  This file contains Task Door which controls the door that the load
 *  cell sits on as spice is weighed.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 

/** @brief   This task waits for the opening wheel to close before dispensing spice.
 *  @details This task controls the motor on the trap door that holds the load cell as it takes measurements. The
 *           door is controlled by one limit switch on either side: one that triggers when it is fully opened and
 *           another that triggers when the door is closed.
 */
void task_door (void* p_params)
{
    //sets limit pin values
    uint8_t limit_close = 18;
    uint8_t limit_open = 5;

    //sets limit pin modes
    pinMode(limit_close, INPUT_PULLUP);
    pinMode(limit_open, INPUT_PULLUP);

    //sets motor pin values and speed
    uint8_t pA1 = 0;
    uint8_t pA2 = 4;
    uint32_t speed = 0;
    
    //names and initializes motor driver object
    Motor_driver door_motor;
    door_motor.initialize(pA1, pA2);

    //initializes and sets the starting state
    uint8_t state = 0;

    //sets internal variables
    bool init = 0;
    bool closing = 0;

    while(true)
    {
        if (state == 0) //waiting state
        {
            //checks if the door has been initialized
            if (init == 1)
            {
                //checks if it is time to dispense
                if (disp_flag.get() == 1)
                {
                    //simulates load cell filling
                    vTaskDelay(1000);
                    //tells the wheel to close
                    close_flag.put(true);
                    state = 1;
                    closing = 0;
                }
            }
            
            //checks if the door is not closed with the limit switch, it should always be closed in this state
            //unless the program has just booted
            else if(digitalRead(limit_close))
            {
                //closes the door
                door_motor.run_forwards(speed);
            }

            //if the door is closed, stops motor and sets initialization variable as true
            else if(!digitalRead(limit_close))
            {
                door_motor.stop_motor();
                init = 1;
            }
        }

        else if (state == 1) //opens and closes the door to dispense spice
        {
            //checks that the door is not fully open
            if(digitalRead(limit_open))
            {
                //sets motor direction based on closing variable
                // run forwards closes, run backwards opens
                if (closing == 0) //opening
                {
                    door_motor.run_backwards(speed);
                }

                //stops the motor if the door fully closes
                else if (!digitalRead(limit_close))
                {
                    door_motor.stop_motor();
                    //resets dispensing share
                    disp_flag.put(false);
                    //resets internal variables
                    state = 0;
                    closing = 0;
                    init = 0;
                }
            }

            //checks if the door is fully open, and starts to close it after a short delay
            else if (!digitalRead(limit_open))
            {
                door_motor.stop_motor();
                vTaskDelay(1000);
                closing = 1;
                door_motor.run_forwards(speed);
            }
        }

        vTaskDelay(100); //10 Hz
    }
}