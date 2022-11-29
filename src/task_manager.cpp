#include <Arduino.h>
#include <HX711.h>
#include <shares.h>


void task_manager (void* p_params)
{

    String state;
    state = "wait";
    bool turn = true;

    float current_position; 
    float desired_position = 0;  
    float current_weight;
    float desired_weight = 0; 
    

    while(true)
    {
        current_position = position.get();
        desired_position = user_position.get(); 
        current_weight = weight.get();
        desired_weight = user_weight.get();

        if(desired_weight == 0 | desired_position == 0)
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
            state = "wait"; 
            turn = true; 
        }

        current_state.put(state); 

        vTaskDelay(1);
    }

}

