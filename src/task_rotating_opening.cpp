#include <Arduino.h>
#include <motor_driver_class.h>
#include <shares.h>


void task_rotating_opening (void* p_params)
{
    uint8_t pinA = 6;
    uint8_t pinB = 7; 
    uint8_t speed_pin = 8; 
    uint16_t speed = 50; 

    Motor_driver rotating_opening (pinA, pinB, speed_pin);

    uint8_t hall_effect1 = 14;
    uint8_t hall_effect2 = 15;
    pinMode(hall_effect1, INPUT);
    pinMode(hall_effect2, INPUT);

    String state;
    float current_position; 
    float desired_position;  
    float current_weight;
    float desired_weight; 


    while(true)
    {
        state = current_state.get();
        current_position = position.get();
        desired_position = user_position.get(); 
        current_weight = weight.get();
        desired_weight = user_weight.get();

        if(state == "dispense")
        {
            if(current_position == desired_position)
            {
                if(current_weight < desired_weight)
                {
                    while(hall_effect1 != HIGH)
                    {
                        rotating_opening.run_forwards(speed); 
                    }
                }
            }
                
            else
            {
                while(hall_effect2 != HIGH)
                {
                    rotating_opening.run_backwards(speed); 
                }
            }
            
        }
        
        else
        {
            while(hall_effect2 != HIGH)
                {
                    rotating_opening.run_backwards(speed); 
                }
        }

        vTaskDelay(1);
    }

}


