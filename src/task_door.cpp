#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_door (void* p_params)
{

    uint8_t limit1 = 18; //18
    uint8_t limit2 = 5; //5
    pinMode(limit1, INPUT_PULLUP);
    pinMode(limit2, INPUT_PULLUP);


    uint8_t pA1 = 0; //1 
    uint8_t pA2 = 4; //3
    uint32_t speed = 0;
    
    Motor_driver door_motor;
    door_motor.initialize(pA1, pA2);

    Serial.println("here");
     uint8_t state = 0;

    while(true)
    {
        if (state == 0) // wait
        {
            if (disp_flag.get() == 1)
            {
                state = 1;
            }
            if(digitalRead(limit1 !=0))
            {
                door_motor.run_forwards(speed);
                if(digitalRead(limit1 =0))
                {
                    door_motor.stop_motor();
                }
            }
        }

        else if (state == 1) //opens and closes door
        {
            if(digitalRead(limit2) != 1)
            {
                door_motor.run_forwards(speed);
            }

            if(digitalRead(limit2) == 1)
            {
                vTaskDelay(5000);

                if(digitalRead(limit1) != 1)
                {
                    door_motor.run_backwards(speed);
                }

                else if (digitalRead(limit1) == 1)
                {
                    state = 0;
                    door_motor.stop_motor();
                    disp_flag.put(false);
                }
            }
        }

        vTaskDelay(100);
    }
    
}