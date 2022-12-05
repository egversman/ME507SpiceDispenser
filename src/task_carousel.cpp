#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 


void task_carousel (void* p_params)
{
    // float selected_position = 2000; 
    // user_position.put(selected_position); 
    float position;

    uint8_t pB1 = 23;
    uint8_t pB2 = 22; 
    uint16_t speed = 10;

    uint8_t halef = 32;
    pinMode(halef, INPUT_PULLUP);

    Motor_driver carousel_motor;

    // //Temporary Flags for testing
    // initalized.put(false);
    // inst_received.put(true);
    // zero.put(false);
    // //end

    carousel_motor.initialize(pB1, pB2);
    uint8_t state = 0;
    
    //initialize internal variables
    bool sense = 0;
    bool back = 1;
    bool corr = 0;
    float del = 0.0;
    while(true)
    {
        if (state == 0) //initialize state
        {
            if (sense == 1)
            {
                carousel_motor.stop_motor();
                vTaskDelay(500);
                if (!digitalRead(halef))
                {
                    sense = 0;
                    back = 1;
                    state = 1;
                    encoder_flag.put(true);
                    //Serial.println("properly zeroed");
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
                    carousel_motor.run_backwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && sense == 0)
                {
                    carousel_motor.run_forwards(speed);
                    if (!digitalRead(halef))
                    {
                        sense = 1;
                        back = 1;
                    }
                }
            }
            
        
        }
        

        else if (state == 1) //waiting state
        {
            if ((inst_received.get() == 1) && (initialized.get() == 1))
            {
                state = 2;
                corr = 0;
                back = 1;
                inst_received.put(false);
            }
        }

        else if (state == 2) //moving to correct index
        {
            del = abs(current_position.get() - user_position.get());
            //Serial.println(del);
            if (corr == 1)
            {
                carousel_motor.stop_motor();
                vTaskDelay(1000);
                del = abs(current_position.get() - user_position.get());
                if (del <= 10)
                {
                    carousel_position.put(true);
                    vTaskDelay(5000);
                    close_flag.put(true);
                    corr = 0;
                    back = 1;
                    state = 1;
                    Serial.println("right position");
                }
                else
                {
                    corr = 0;
                }
            }
            else
            {
                if (back == 1 && corr == 0)
                {
                    carousel_motor.run_backwards(speed);
                    if (del <= 10)
                    {
                        corr = 1;
                        back = 0;
                    }
                }
                else if (back == 0 && corr == 0)
                {
                    carousel_motor.run_forwards(speed);
                    if (del <= 10)
                    {
                        corr = 1;
                        back = 1;
                    }
                }
            }
        }
    }
}