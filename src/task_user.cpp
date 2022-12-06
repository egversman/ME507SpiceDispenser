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
    //float startIdx = current_position.get();
    float startIdx = 5;
    if (fmod(startIdx, 1) != 0) 
    {
        Serial.print("Error: Carousel is between indexes");
    }
    
    float input[8][2] = {{0, 1.1}, {1, 8.54}, {2, 7.32}, {3, 0}, {4, 0}, {5, 9.221}, {6, 15.23}, {7, 0}};
    SpicySort sortObj = SpicySort(input, (uint8_t) startIdx);
    SpicyLinkedList sortedLst = sortObj.sort();

    while(true)
    {
        while(sortedLst.getSize() != 0)
        {
            Node* removed = sortedLst.pop();
            desired_position.put(removed->getSpiceId());
            desired_weight.put(removed->getAmount());
            Serial.print(desired_position.get());
            Serial.print(desired_weight.get());
        }

        vTaskDelay(100);
    }
     
}