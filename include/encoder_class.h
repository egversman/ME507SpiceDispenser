/** @file encoder_class.h
 *  This is the header file for the encoder class which is used to create the encoder object.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>

/** @brief Class for the encoder.
 */
class Encoder
{

private:

    uint8_t pinA;
    uint8_t pinB;
    uint16_t ppr;

public: 

    bool new_A;
    bool new_B;
    float position;
    int32_t ticks;

    Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr);


    float get_position (bool last_A, bool last_B);
    
};
