#include <Arduino.h>
#include <HX711.h>
#include <shares.h>


void task_load_cell (void* p_params)
{

    uint8_t pin_DOUT = 17;
    uint8_t pin_SCK = 4;

    float calibration;
    float weight = 0;
    
    HX711 scale;
    scale.begin(pin_DOUT, pin_SCK);    
    scale.set_scale(-400);
    scale.tare();            
    
    while(true)
    {
        Serial.print("\t\t\t\tSingle Weight Reading:\t");
        Serial.print(scale.get_units(), 1);
        Serial.print("\t\t Weight Average:\t");
        Serial.println(scale.get_units(10), 5);

        weight = (scale.get_units(10), 5);
        current_weight.put(weight);
        
        vTaskDelay(100);
     
  }
}

