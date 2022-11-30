#include <Arduino.h>
#include <encoder_class.h>


Encoder :: Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t ppr)
{
    last = 0; 
    position = 0.0; 
    ticks = 0;
    pinA = input_pinA;
    pinB = input_pinB;
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    
}


int32_t Encoder :: get_position (long last_state)
{
    long Astate; 
    long Bstate;

    Astate = digitalRead(pinA);
    Bstate = digitalRead(pinB);

    if(Astate != last_state)
    {
        if(Bstate != Astate)
        {
            ticks--;
        }

        else
        {
            ticks++;
        }
    }


    last = Astate;

    position = ticks * (12 / ppr);

    return last; 
    return position; 
}
