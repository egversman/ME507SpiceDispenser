#include <Arduino.h>
#include <HX711.h>
#include <shares.h>
#include <motor_driver_class.h> 
#include<task_carousel_motor.h>
#include<task_door.h>
#include<task_encoder.h>
#include<task_load_cell.h>
#include<task_rotating_opening.h>
#include<task_manager.h>


void setup ()
{
    Serial.begin (115200);           
    while (!Serial)
    {                                
    }

    xTaskCreate (task_encoder, "Encoder", 2048, NULL, 2, NULL);
    xTaskCreate (task_door, "Dispenser Door", 2048, NULL, 3, NULL);
    xTaskCreate (task_load_cell, "Load Cell", 2048, NULL, 1, NULL);
    xTaskCreate (task_rotating_opening, "Rotating Opening", 2048, NULL, 5, NULL);
    xTaskCreate (task_carousel_motor, "Carousel Motor", 2048, NULL, 6, NULL);
    xTaskCreate (task_manager, "Carousel Motor", 2048, NULL, 4, NULL);
}

void loop ()
{
    vTaskDelay(50000);

}
