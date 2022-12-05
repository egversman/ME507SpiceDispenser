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
Share<bool> initalized("initalized");
Share<float> user_position("input position");
Share<bool> inst_recieved("instruction recieved");
Share<bool> carousel_position("carousel desired position met");
Share<bool> zero("zero the carousel");
Share<bool> encoder_flag("tells encoder to read");
Share<bool> close_flag("tells to close the dispenser");
Share<bool> disp_flag("tells when to release");


void setup() 
{

    close_flag.put(true);
    disp_flag.put(true);
    carousel_position.put(false);
    user_position.put(200);
    Serial.begin (115200);           
    while (!Serial)
    {                                
    }
    //xTaskCreate (task_encoder, "Encoder", 5120, NULL, 6, NULL);
    //xTaskCreate (task_carousel, "Carousel Motor", 5120, NULL, 4, NULL);
    xTaskCreate (task_door, "Door Motor", 5120, NULL, 3, NULL);
    //xTaskCreate (task_load_cell, "Load Cell", 5120, NULL, 5, NULL);
    //xTaskCreate (task_opening, "Opening Motor", 5120, NULL, 2, NULL);

    uint8_t idx1 = 2;
    uint8_t idx2 = 8;

}


void loop() 
{
    
    vTaskDelay(50000);
  
}

