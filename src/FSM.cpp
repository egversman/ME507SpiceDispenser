#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>


void FMS (void* p_params)
{

    String state = "initialize";
    
    while(true)
    {
        if(state == "initialize")
        {
            
        }

    
      
        vTaskDelay(100);
    }
    
}