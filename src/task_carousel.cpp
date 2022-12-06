/** @file task_carousel.cpp
 *  This file contains Task Carousel which runs the main rotary system
 *  that selects the requested spice index.
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

/** @brief   This task positions the carousel based on a desired index using encoder readings.
 *  @details This task uses an encoder along with a hall effect sensor to get a position value for
 *           the motor as it rotates. The position reading is set to zero every time the hall effect
 *           sensor passes the magnet. This task uses the desired position to identify the correct 
 *           index and moves to that position using the difference between reading and target values.
 */
void task_carousel (void* p_params)
{
    //sets position variable
    float position;

    //sets pin numbers and speed value for motor
    uint8_t pB1 = 23;
    uint8_t pB2 = 22; 
    uint16_t speed = 10;

    //sets hall effect sensor pin number and mode
    uint8_t halef = 32;
    pinMode(halef, INPUT_PULLUP);

    //names the motor driver object
    Motor_driver carousel_motor;

    //initializes the motor driver object with the correct pins
    carousel_motor.initialize(pB1, pB2);

    //sets the starting state variable
    uint8_t state = 0;
    
    //initialize internal variables
    bool sense = 0;
    bool back = 1;
    bool corr = 0;
    float del = 0.0;

    while(true)
    {
        if (state == 0) //initialization state, moves the carousel to the zero position
        {
            if (sense == 1)
            {
                //checks that the sensor is reading continuously after 0.5 seconds
                carousel_motor.stop_motor();
                vTaskDelay(500);
                if (!digitalRead(halef)) 
                {
                    sense = 0;
                    back = 1;
                    state = 1;
                    encoder_flag.put(true);
                }
                else
                {
                    sense = 0;
                }
            }
            else
            {
                //moves back and forth until the sensor is properly targeted
                if (back == 1 && sense == 0)
                {
                    carousel_motor.run_backwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && sense == 0)
                {
                    carousel_motor.run_forwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 1;
                    }
                }
            }
        }
        

        else if (state == 1) //waiting state
        {
            //changes state if instructions have been sent and the opening wheel is initialized
            if ((inst_received.get() == 1) && (initialized.get() == 1))
            {
                state = 2;
                corr = 0;
                back = 1;
                inst_received.put(false);
            }
        }

        else if (state == 2) //targets and moves to the requested index
        {
            //delta value that checks proximity to desired position
            del = abs(current_position.get() - user_position.get());
            
            //corr triggers when the delta value is read as being within
            //the acceptable tolerance
            if (corr == 1)
            {
                carousel_motor.stop_motor();
                vTaskDelay(1000);
                del = abs(current_position.get() - user_position.get());
                //re-evaluates del and checks if it is still in range
                if (del <= 10)
                {
                    //the position has passed, sets carousel_position as true to
                    //tell the system it has reached the proper value
                    carousel_position.put(true);

                    //this is implemented due to the load cell not working, this simply waits 5
                    //seconds and then tells the opening wheel to close to simulate dispensing
                    vTaskDelay(5000);
                    close_flag.put(true);

                    //resets variables for next readings
                    corr = 0;
                    back = 1;
                    state = 1;
                }
                else
                {
                    corr = 0;
                }
            }
            else
            {
                //moves back and forth until del value is adequate
                if (back == 1 && corr == 0)
                {
                    carousel_motor.run_backwards(speed);
                    if (del <= 10)
                    {
                        corr = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && corr == 0)
                {
                    carousel_motor.run_forwards(speed);
                    if (del <= 10)
                    {
                        corr = 1;
                        back = 1;
                    }
                }
            }
        }
        vTaskDelay(1); //1000 Hz
    }
}