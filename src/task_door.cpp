#include <Arduino.h>
#include <motor_driver_class.h>
#include <shares.h>


void task_door (void* p_params)
{
    uint8_t pinA = 16;
    uint8_t pinB = 17; 
    uint8_t speed_pin = 18; 
    uint16_t speed = 50; 

    Motor_driver door (pinA, pinB, speed_pin);

    uint8_t limit_switch1 = 17;
    uint8_t limit_switch2 = 18;
    pinMode(limit_switch1, INPUT);
    pinMode(limit_switch2, INPUT);

    float current_weight;
    float desired_weight; 
    String state;

    while(true)
    {
        current_weight = weight.get();
        desired_weight = user_weight.get();
        state = current_state.get();

        if(state == "dispense")
        {
            if(current_weight >= desired_weight)
            {
                while(limit_switch1 != HIGH)
                {
                    door.run_forwards(speed);
                }
            }

            if(limit_switch1 == HIGH)
            {
                vTaskDelay(3000);
                while(limit_switch2 != HIGH)
                {
                    door.run_backwards(speed);
                }
            }
        }

        else
        {
            while(limit_switch2 != HIGH)
                {
                    door.run_backwards(speed);
                }
        }
        
        vTaskDelay(1);
    }

}


