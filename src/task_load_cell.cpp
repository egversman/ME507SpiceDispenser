/** @file task_load_cell.cpp
 *  This file contains Task Load Cell which continuously takes load cell readings.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */
#include <Arduino.h>
#include <HX711.h>
#include <shares.h>

/** @brief   This task takes load cell readings over time.
 *  @details This task creates a load cell object and takes readings continuously. The readings
 *           are sent to the other tasks using a shared weight variable. This task has been able to take 
 *           functional readings but is not implemented into the final product because our load cell
 *           broke. With a working load cell, this file would also compare the current weight value with
 *           the desired weight value and trigger close_flag if the weight value reached the requested
 *           value.
 */
void task_load_cell (void* p_params)
{
    //sets load cell pins
    uint8_t pin_DOUT = 17;
    uint8_t pin_SCK = 4;

    //initializes variables
    float calibration;
    float weight = 0;
    
    //initializes the load cell object and passes in parameters
    HX711 scale;
    scale.begin(pin_DOUT, pin_SCK);    
    scale.set_scale(-400);
    scale.tare();            
    
    while(true)
    {
        //continuously prints load cell values
        Serial.print("\t\t\t\tSingle Weight Reading:\t");
        Serial.print(scale.get_units(), 1);
        Serial.print("\t\t Weight Average:\t");
        Serial.println(scale.get_units(10), 5);

        //passes the shared weight variable to other tasks
        weight = (scale.get_units(10), 5);
        current_weight.put(weight);
        
        vTaskDelay(100); //10 Hz
     
  }
}

