#include <Arduino.h>
#include <encoder_class.h>
#include <PrintStream.h>
#include <shares.h>
#include <taskshare.h>         
#include <taskqueue.h>


void task_encoder (void* p_params)
{
    uint8_t halef = 32;
    uint8_t pinA = 35;
    uint8_t pinB = 34;
    uint16_t ppr_val = 5120;
    bool last_A;
    bool last_B;
    
    pinMode(halef, INPUT_PULLUP);

    Encoder encoder1(pinA, pinB, ppr_val);
    last_A = 0;
    last_B = 0;
    uint8_t state = 0;

    while(true)
    {
        if (state == 0) //waiting
        {
            // if (encoder_flag.get() == 1)
            // {
            //     state = 1;
            //     encoder_flag.put(false);
            // }
            state = 1;
        }

        if (state == 1) //reading
        {
            encoder1.get_position(last_A, last_B);
            last_A = encoder1.new_A;  
            last_B = encoder1.new_B;
            current_position.put(encoder1.position);
            //Serial.print("Encoder Ticks:\t");
            Serial.println(encoder1.position);
            //Serial.println(current_position.get());


            if(!digitalRead(halef))
            {
                encoder1.ticks = 0;
            }
            
            // else if (carousel_position.get() == 1)
            // {
            //     state = 0;
            //     carousel_position.put(false);
            // }

        }
        vTaskDelay(0.001);
    }
    
}

