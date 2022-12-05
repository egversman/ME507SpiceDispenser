#include <Arduino.h>
#include <PrintStream.h>
#include <shares.h> 
#include <taskshare.h>         
#include <taskqueue.h>
#include <motor_driver_class.h> 
#include <SpicyNode.h> 
#include <SpicySort.h> 
#include <SpicyLinkedList.h> 


void task_user (void* p_params)
{
    float startIdx = current_position.get();
    if (fmod(startIdx, 1) != 0) 
    {
        Serial.print("Error: Carousel is between indexes");
    }
    
    float input[8][2];
    SpicySort sortObj = SpicySort(input, (int) startIdx);
    SpicyLinkedList sortedLst = sortObj.sort();

    while(true)
    {
        while(sortedLst.getSize() != 0)
        {
            Node* removed = sortedLst.pop();
            user_position.put(removed->getSpiceId());
            user_weight.put(removed->getAmount());
        }

        vTaskDelay(100);
    }
     
}