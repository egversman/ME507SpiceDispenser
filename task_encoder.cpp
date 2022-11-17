#include <Arduino.h>
#include <encoder_class.h>


void task_encoder (void* p_params)
{
    uint8_t pinA = 13;
    uint8_t pinB = 12;
    int32_t last_state;
    int32_t position;

    Encoder encoder1(pinA, pinB);
    last_state = encoder1.position;

    while(true)
    {
        encoder1.get_position(last_state);
        last_state = encoder1.last_state; 
        position = encoder1.position; 
        vTaskDelay(1);
    }
    
}

