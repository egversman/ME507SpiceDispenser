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
    
    float input[8][2] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}};
    SpicySort sortObj = SpicySort(input, (uint8_t) startIdx);
    SpicyLinkedList sortedLst = sortObj.sort();

    while(true)
    {
        while(sortedLst.getSize() != 0)
        {
            Node* removed = sortedLst.pop();
            user_position.put(removed->getSpiceId());
            user_weight.put(removed->getAmount());
        }

        Serial.print(user_position.get());
        Serial.print("\t");
        Serial.println(user_weight.get());

        vTaskDelay(1000);
    }
     
}


