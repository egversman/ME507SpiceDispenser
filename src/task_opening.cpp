#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_opening (void* p_params)
{
    float user_position = 2000;
    float position;

    uint8_t pB1 = 21;
    uint8_t pB2 = 19; 
    uint16_t speed = 0;
    uint8_t  halef = 33;

    pinMode(halef, INPUT_PULLUP);

    Motor_driver opening;
    opening.initialize(pB1, pB2);
    uint8_t state = 2;
    bool sense = 0;
    bool back = 1;

    while(true)
    {
        if (state == 0) //closes opening
        {

            if (!digitalRead(halef))
                {
                    opening.run_backwards(speed);
                    vTaskDelay(300);
                    if (digitalRead(halef))
                    {
                        opening.stop_motor();
                        state = 1;
                        Serial.println("closed");
                        close_flag.put(false);
                    }
                    else
                    {
                        sense = 0;
                    }
                }
        }
        else if (state == 1) //waits for proper position
        {
            if (carousel_position.get() == 1)
            {
                sense = 0;
                state = 2;
                carousel_position.put(false);
            }
            else if (close_flag.get() == 1)
            {
                state = 0;
            }
        }

        else if (state == 2) // opens, targets hall effect
        {
           if (sense == 1)
            {
                opening.stop_motor();
                vTaskDelay(500);
                if (!digitalRead(halef))
                {
                    sense = 0;
                    back = 1;
                    state = 1;
                    Serial.println("open");
                }
                else
                {
                    sense = 0;
                }
            }
            else
            {
                if (back == 1 && sense == 0)
                {
                    opening.run_backwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && sense == 0)
                {
                    opening.run_forwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 1;
                    }
                }
            }
        
        }
        
    vTaskDelay(1);
    }
}