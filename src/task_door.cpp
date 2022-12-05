#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_door (void* p_params)
{

    uint8_t limit_close = 18; //18
    uint8_t limit_open = 5; //5
    pinMode(limit_close, INPUT_PULLUP);
    pinMode(limit_open, INPUT_PULLUP);


    uint8_t pA1 = 0; //1 
    uint8_t pA2 = 4; //3
    uint32_t speed = 0;
    
    Motor_driver door_motor;
    door_motor.initialize(pA1, pA2);

    Serial.println("here");
     uint8_t state = 0;
     bool init = 0;
     bool closing = 0;

    while(true)
    {
        if (state == 0) // wait
        {
            if (init == 1)
            {

                if (disp_flag.get() == 1)
                {
                    vTaskDelay(1000); //simulates load cell filling
                    close_flag.put(true);
                    state = 1;
                    closing = 0;
                    //Serial.println("moving to state 1");
                }
            }

            else if(digitalRead(limit_close))
            {
                door_motor.run_forwards(speed);
            }

            else if(!digitalRead(limit_close))
            {
                door_motor.stop_motor();
                init = 1;
                Serial.println("door initialized");
            }
        }

        else if (state == 1) //opens and closes door
        {
            // run forwards closes, run backwards opens
            if(digitalRead(limit_open)) //doesn't read open switch
            {
                if (closing == 0)
                {
                    door_motor.run_backwards(speed); //opens
                }
                else if (!digitalRead(limit_close))
                {
                    door_motor.stop_motor();
                    disp_flag.put(false);
                    state = 0;
                    closing = 0;
                    init = 0;
                    Serial.println("dispensed");
                }
            }

            else if (!digitalRead(limit_open)) //hits open switch, stops and waits a second
            {
                door_motor.stop_motor();
                vTaskDelay(1000);
                closing = 1;
                door_motor.run_forwards(speed);
            }
        }

        vTaskDelay(100);
    }
    
}