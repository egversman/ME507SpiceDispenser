#include <Arduino.h>
#include <HX711.h>
#include <shares.h>


void task_load_cell (void* p_params)
{

  uint8_t pin_DOUT = 10;
  uint8_t pin_SCK = 11;
  float calibration;
  

  HX711 scale;


  //Calibration
  scale.begin(pin_DOUT, pin_SCK);

  if (scale.is_ready()) 
  {
    scale.set_scale();    
    scale.tare();
    calibration = scale.get_units(10);
  }
  
  else
  {
    Serial.println("HX711 not connected");
    while(true)
    {
      vTaskDelay(1000);
    }
  }

  //Setup
  scale.set_scale(calibration);
 

  //Loop 
  while(true)
  {
    scale.get_units(10); 
    weight.put(scale.get_units(10));
    vTaskDelay(1); 
  }
}