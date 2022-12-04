#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_carousel (void* p_params)
{
    float user_position = 2000;
    float position;

    uint8_t pB1 = 23;
    uint8_t pB2 = 22; 
    uint16_t speed = 0;

    uint8_t halef = 32;

    Motor_driver carousel_motor;

    carousel_motor.initialize(pB1, pB2);

    while(inst_recieved.get() && !correct_position.get())
    {
        while(!zero.get())
        {
            carousel_motor.run_backwards(speed);

            if(!digitalRead(halef))
            {
            zero.put(true);
            }
        }    

         position = current_position.get(); 
        

        if(position < user_position && zero.get())
        {
            carousel_motor.run_backwards(speed);
            
            
        }
      
        vTaskDelay(1);
    }
}