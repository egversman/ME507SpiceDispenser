/** @file encoder_class.cpp
 *  This is the source file for the encoder class which is used to create the encoder object.
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

/** @brief Constructor that initializes variables and sets the pin modes.
*   @param input_pinA The input for the A pin from the encoder.
*   @param input_pinB The input for the B pin from the encoder.
*   @param input_ppr  An input for the PPR value for the specific encoder.
*/
Encoder :: Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr)
{
    //instantiates variables
    bool last_A = 0; 
    bool last_B = 0;
    position = 0.0; 
    ticks = 0;

    //sets pin and ppr variables
    pinA = input_pinA;
    pinB = input_pinB;
    ppr = input_ppr; 

    //sets pin modes
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    
}

/** @brief   A function that returns the position from the encoder.
*   @param   last_A The last read A value, used to evaluate direction of rotation.
*   @param   last_B The last read B value, used to evaluate direction of rotation.
*   @return  new_A, the new A value to be passed in as last_A for the next measurement.
*   @return  new_B, the new B value to be passed in as last_B for the next measurement.
*   @return  position, returned as 100x the index value to allow a higher resolution
*            in measured values.
*/
float Encoder :: get_position (bool last_A, bool last_B)
{
    //initializes variables
    bool Astate; 
    bool Bstate;
    float pos = 0.0;

    //sets state values using pin readings
    Astate = digitalRead(pinA);
    Bstate = digitalRead(pinB);

    //this block of code uses a series of statements that evaluate direction based on 
    //the change of A and B and adds or subtracts ticks accordingly
    if((Astate != last_A)|(Bstate != last_B))
    {
        if((last_A == 0) && (last_B == 0))
        {
            if (Astate == 1)
            {
                ticks --;
            }
            else if (Bstate == 1)
            {
                ticks ++;
            }
        }
        if((last_A == 0) && (last_B == 1))
        {
            if (Astate == 1)
            {
                ticks ++;
            }
            else if (Bstate == 0)
            {
                ticks --;
            }
        }
        if((last_A == 1) && (last_B == 0))
        {
            if (Astate == 0)
            {
                ticks ++;
            }
            else if (Bstate == 1)
            {
                ticks --;
            }
        }
        if((last_A == 1) && (last_B == 1))
        {
            if (Astate == 0)
            {
                ticks --;
            }
            else if (Bstate == 0)
            {
                ticks ++;
            }
        }

    }

    //sets new A and B values for the next computation
    new_A = Astate;
    new_B = Bstate;

    //sets position as a function of ticks/ppr, with a multiplier value of 800
    //to ensure returned values are 100x the index (8 indices from 0-7)
    pos = -800*ticks/ppr; 

    //ensures that the returned position value only goes from 0-799
    if (pos < 0)
    {
        position = 799 + pos;
    }
    else
    {
        position = pos;
    }

    //returned values
    return new_A;
    return new_B;
    return position; 
}
