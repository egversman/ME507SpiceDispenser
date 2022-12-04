#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_carousel (void* p_params)
{
    float selected_position = 2000; 
    user_position.put(selected_position); 
    float position;

    uint8_t pB1 = 23;
    uint8_t pB2 = 22; 
    uint16_t speed = 0;

    uint8_t halef = 32;

    Motor_driver carousel_motor;

    //Temporary Flags for testing
    initalized.put(false);
    inst_recieved.put(true);
    zero.put(false);
    //end

    carousel_motor.initialize(pB1, pB2);
    while(true)
    {
    // Initalization of the carousel which makes sure that it first
    // zeros itself by moving to the hall effect sensor 
    if(!initalized.get())
    {
        while(!zero.get())
        {
            carousel_motor.run_backwards(speed);

            if(digitalRead(halef))
            {
               
                zero.put(true);
                initalized.put(true);
                Serial.print('Z');
                //int i;
                //for (i=0 ; i<=100; i++)
                //{
                //   carousel_motor.run_forwards(speed);
                //   vTaskDelay(1);
               // }
            }
            vTaskDelay(10);
        }   
    vTaskDelay(1);
    }

    // This will move the carousel to the spice that is loaded from the queue list
    while(!inst_recieved.get() && !carousel_position.get() && zero.get())
    { 
        Serial.print('T');
         position = current_position.get(); 
        

        if(position < user_position.get())
        {
            carousel_motor.run_backwards(speed);
        }
        else 
        {
            carousel_position.put(true);
        }
        vTaskDelay(1);
    }
    }
    vTaskDelay(10);
}