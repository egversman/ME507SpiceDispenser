/** @file task_opening.cpp
 *  This file contains Task Opening which controls the wheel that dispenses spice onto the load cell.
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

/** @brief   This task uses a hall effect sensor and motor to dispense spice onto the load cell.
 *  @details This task creates an opening motor object that cross references its position with a 
 *           hall effect sensor to open and close. When the hall effect sensor reads a signal,
 *           the wheel is in the open position. To close, the wheel rotates for a set duration
 *           that was chosen through testing. This did not need to be precise as the vast majority
 *           of the wheel represents the "closed" state.
 */
void task_opening (void* p_params)
{
    //sets position variable
    float position;

    //sets motor pins and speed
    uint8_t pB1 = 21;
    uint8_t pB2 = 19; 
    uint16_t speed = 0;

    //sets hall effect sensor pin and pin mode
    uint8_t  halef = 33;
    pinMode(halef, INPUT_PULLUP);

    //creates motor driver object and passes in pins
    Motor_driver opening;
    opening.initialize(pB1, pB2);

    //initializes and sets the starting state
    uint8_t state = 2;

    //initializes variables
    bool sense = 0;
    bool back = 1;
    initialized.put(false);

    while(true)
    {
        if (state == 0) //closes opening
        {
            //checks if the hall effect sensor is till reading
            if (!digitalRead(halef))
                {
                    //closes the wheel
                    opening.run_backwards(speed);
                    vTaskDelay(300);
                    if (digitalRead(halef))
                    {
                        //stops the motor, and returns to state 1
                        opening.stop_motor();
                        state = 1;

                        //resets close flag
                        close_flag.put(false);
                    }
                    else
                    {
                        sense = 0;
                    }
                }
        }
        else if (state == 1) //waiting for a command
        {
            //checks that initialization variable is false, which will only happen on initial boot up
            if (initialized.get() == 0)
            {
                //sets that it has been calibrated and goes to state to close the wheel
                initialized.put(true);
                disp_flag.put(false);
                state = 0;
            }

            //checks if the carousel is in the proper position, then opens the wheel
            else if (carousel_position.get() == 1)
            {
                sense = 0;
                state = 2;
                carousel_position.put(false);
            }

            //checks if it has been told to close
            else if (close_flag.get() == 1)
            {
                state = 0;
                close_flag.put(false);
                disp_flag.put(true);
            }
        }

        else if (state == 2) //identifies hall effect sensor to set to open position

        //this task starts in this state so that the wheel can identify the open position to then close
        //the wheel, ensuring the wheel initializes in the closed state
        {
           if (sense == 1)
            {
                //checks that the sensor is still reading after half a second
                opening.stop_motor();
                vTaskDelay(500);
                if (!digitalRead(halef))
                {
                    //resets internal variables, moves to wait state
                    sense = 0;
                    back = 1;
                    state = 1;
                }
                else
                {
                    //sets sense to 0 if it fails the second position check
                    sense = 0;
                }
            }
            else
            {
                //moves the wheel back and forth to line up with the magnet
                if (back == 1 && sense == 0)
                {
                    opening.run_backwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && sense == 0)
                {
                    opening.run_forwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 1;
                    }
                }
            }
        
        }
        
        
    vTaskDelay(1); //1000 Hz 
    }
}