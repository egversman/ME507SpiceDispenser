/** @file task_encoder.cpp
 *  This file contains Task Encoder which continuously takes encoder readings.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>
#include <encoder_class.h>
#include <PrintStream.h>
#include <shares.h>
#include <taskshare.h>         
#include <taskqueue.h>

/** @brief   This task initializes the encoder object and takes encoder readings.
 *  @details This task creates an encoder object using the encoder class and executes the
 *           encoder readings. State transitions are not relevant in this task because it does
 *           the same thing continuously until the microcontroller stops running.
 */
void task_encoder (void* p_params)
{
    //sets hall effect pin
    uint8_t halef = 32;

    //sets encoder pins and ppr value
    uint8_t pinA = 35;
    uint8_t pinB = 34;
    uint16_t ppr_val = 5120;

    //sets variables for last_A and last_B
    bool last_A;
    bool last_B;
    
    //sets the hall effect pin mode
    pinMode(halef, INPUT_PULLUP);

    //initializes the encoder object with the pins and ppr
    Encoder encoder1(pinA, pinB, ppr_val);

    //sets initial values
    last_A = 0;
    last_B = 0;

    //initializes start state
    uint8_t state = 0;

    while(true)
    {
        if (state == 0) //waiting state
        {
            //we initially had a state that used a flag to tell when to take readings, but we realized
            //it made far more sense to have the encoder always take readings
            state = 1;
        }

        if (state == 1) //reading state
        {
            //continuously gets the encoder position
            encoder1.get_position(last_A, last_B);

            //sets new values to pass back in to the get_position function
            last_A = encoder1.new_A;  
            last_B = encoder1.new_B;

            //sets the current position shared variable
            current_position.put(encoder1.position);
            
            //zero the position if the hall effect sensor is triggered
            if(!digitalRead(halef))
            {
                encoder1.ticks = 0;
            }

        }
        vTaskDelay(0.001); //1 MHz
    }
}

