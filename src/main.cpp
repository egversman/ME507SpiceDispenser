#include <Arduino.h>
#include <task_encoder.h> 
#include <PrintStream.h>
#include <task_carousel.h> 
#include <task_opening.h>
#include <task_door.h>
#include <task_load_cell.h>
#include <FSM.h>
#include <taskshare.h>         
#include <taskqueue.h>
#include <shares.h>


Share<float> current_position ("Position");
Queue<float> current_weight (100, "Weight");


void setup() 
{
  
    Serial.begin (115200);           
    while (!Serial)
    {                                
    }

    //xTaskCreate (task_encoder, "Encoder", 5120, NULL, 6, NULL);
    //xTaskCreate (task_carousel, "Carousel Motor", 5120, NULL, 4, NULL);
    //xTaskCreate (task_door, "Door Motor", 5120, NULL, 3, NULL);
    xTaskCreate (task_load_cell, "Load Cell", 5120, NULL, 5, NULL);
   // xTaskCreate (task_opening, "Carousel Motor", 5120, NULL, 2, NULL);
    xTaskCreate (FSM, "Finite State Machine", 5120, NULL, 1, NULL);

}


void loop() 
{
    
    vTaskDelay(50000);
  
}

