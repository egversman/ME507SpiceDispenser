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
    int32_t last_state;
    
    pinMode(halef, INPUT_PULLUP);

    Encoder encoder1(pinA, pinB, ppr_val);
    last_state = 0;
    
    Serial.print("test");

    while(true)
    {
        encoder1.get_position(last_state);
        last_state = encoder1.last;  
        current_position.put(encoder1.position);
        Serial.print("Encoder Ticks:\t");
        Serial.println(encoder1.position);

        if(!digitalRead(halef))
        {
            encoder1.ticks = 0;
        }

        vTaskDelay(100);
    }
    
}

