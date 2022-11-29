#include <Arduino.h>
#include <HX711.h>
#include <shares.h>
#include <motor_driver_class.h> 


void task_carousel_motor (void* p_params)
{
    uint8_t pinA = 10;
    uint8_t pinB = 11; 
    uint8_t speed_pin = 12; 
    uint16_t speed = 50; 
    
    bool direction;
    float current_position; 
    float desired_position; 
    String state;
    
    Motor_driver carousel (pinA, pinB, speed_pin);

    while(true)
    {
        direction = spin_direction.get(); 
        current_position = position.get();
        desired_position = user_position.get(); 
        state = current_state.get();

        
        if(state == "turning")
        {
            if (current_position != desired_position)
            {
                if (direction != true)
                {
                    carousel.run_forwards(speed);
                }

                if (direction == true)
                {
                    carousel.run_backwards(speed);
                }
            
            }
        }

        vTaskDelay(1);
    }
}

