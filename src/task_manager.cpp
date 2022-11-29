#include <Arduino.h>
#include <HX711.h>
#include <shares.h>


void task_manager (void* p_params)
{

    String state;
    state = "wait";
    bool turn = true;

    float current_position; 
    float desired_position;  
    float current_weight;
    float desired_weight; 
    

    while(true)
    {
        current_position = position.get();
        desired_position = user_position.get(); 
        current_weight = weight.get();
        desired_weight = user_weight.get();

        if(desired_weight == NULL | desired_position == NULL)
        {
            state = "wait";
        }

        if(desired_position != current_position && turn == true)
        {
            state = "turning";
        }

        if(desired_position == current_position && desired_weight != current_weight)
        {
            state = "dispense";
            turn = false; 
        }

        if(state = "dispense" && desired_weight == current_weight)
        {
            state = "turning"; 
            turn = true; 
        }

        current_state.put(state); 

        vTaskDelay(1);
    }

}

