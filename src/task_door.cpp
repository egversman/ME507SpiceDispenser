#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_door (void* p_params)
{

    user_position.put((float) 2000);
    bool move;
    float last_position = 0; 
    String dispense = "yes";

    uint8_t limit1 = 18;
    uint8_t limit2 = 5;
    pinMode(limit1, INPUT_PULLUP);
    pinMode(limit2, INPUT_PULLUP);


    uint8_t pA1 = 1;
    uint8_t pA2 = 3;
    uint32_t speed = 0;
    
    Motor_driver door_motor;
    door_motor.initialize(pA1, pA2);

    while(true)
    {
        move = door_open.get();
       
        if(move == 1)
        {
            while(digitalRead(limit2) != 1)
            {
                door_motor.run_forwards(speed);
            }

            if(digitalRead(limit2) == 1)
            {
                vTaskDelay(3000);

                while(digitalRead(limit1) != 1)
                {
                    door_motor.run_backwards(speed);
                }

                door_open.put(0);
            }
        }

        vTaskDelay(1);
    }
    
}