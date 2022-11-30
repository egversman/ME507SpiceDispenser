#include <Arduino.h>
#include <encoder_class.h>
#include <shares.h>


void task_encoder (void* p_params)
{
    uint8_t pinA = 32;
    uint8_t pinB = 33;
    int32_t last_state;

    Encoder encoder1(pinA, pinB, 5120);
    last_state = encoder1.position;

    bool direction;

    while(true)
    {
        encoder1.get_position(last_state);
        last_state = encoder1.last_state; 
        position.put(encoder1.position); 

        direction = spin_direction.get();
        if(encoder1.position == 12 && direction == true)
        {
            last_state = 0;
        }
         if(encoder1.position == 0 && direction == false)
        {
            last_state = 12;
        }

        vTaskDelay(1);
    }
    
}

