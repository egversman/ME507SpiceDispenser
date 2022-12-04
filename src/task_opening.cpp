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

    while(true)
    {
        position = current_position.get(); 

        if(position > user_position-100 && position < position+100)
        {
            if(digitalRead(halef) == LOW)
            {
                opening.run_forwards(speed);
            }
        }
        else
        {
            if(digitalRead(halef) == HIGH)
            {
                opening.run_backwards(speed);
            }
            else
            {
                vTaskDelay(3000);
            }
        }
      
        vTaskDelay(1);
    }
}