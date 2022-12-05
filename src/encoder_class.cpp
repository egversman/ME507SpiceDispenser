#include <Arduino.h>
#include <encoder_class.h>
#include <PrintStream.h>


// Encoder :: Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr)
// {
//     last = 0; 
//     position = 0.0; 
//     ticks = 0;

//     pinA = input_pinA;
//     pinB = input_pinB;
//     ppr = input_ppr; 

//     pinMode(pinA, INPUT);
//     pinMode(pinB, INPUT);
    
// }


// int32_t Encoder :: get_position (long last_state)
// {
//     long Astate; 
//     long Bstate;

//     Astate = digitalRead(pinA);
//     Bstate = digitalRead(pinB);

//     if(Astate != last_state)
//     {
//         if(Bstate != Astate)
//         {
//             ticks--;
//         }

//         if(Bstate == Astate)
//         {
//             ticks++;
//         }
//     }

//     last = Astate;

//     position = ticks; 

//     return last; 
//     return position; 
// }

// #include <Arduino.h>
// #include <encoder_class.h>
// #include <PrintStream.h>


Encoder :: Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr)
{
    bool last_A = 0; 
    bool last_B = 0;
    position = 0.0; 
    ticks = 0;

    pinA = input_pinA;
    pinB = input_pinB;
    ppr = input_ppr; 

    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    
}


float Encoder :: get_position (bool last_A, bool last_B)
{
    bool Astate; 
    bool Bstate;
    float pos = 0.0;

    Astate = digitalRead(pinA);
    Bstate = digitalRead(pinB);

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

    new_A = Astate;
    new_B = Bstate;

    pos = -3600*ticks/ppr; 
    if (pos < 0)
    {
        position = 790 + pos;
    }
    else
    {
        position = pos;
    }

    return new_A;
    return new_B;
    return position; 
}
