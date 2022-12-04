#include <Arduino.h>
#include <encoder_class.h>
#include <PrintStream.h>


Encoder :: Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr)
{
    last = 0; 
    position = 0.0; 
    ticks = 0;

    pinA = input_pinA;
    pinB = input_pinB;
    ppr = input_ppr; 

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

        if(Bstate == Astate)
        {
            ticks++;
        }
    }

    last = Astate;

    position = ticks; 

    return last; 
    return position; 
}
