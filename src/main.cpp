/** @file main.cpp
 *  This is the main file for the term project implementation.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>
#include <task_encoder.h> 
#include <PrintStream.h>
#include <task_carousel.h> 
#include <task_opening.h>
#include <task_door.h>
#include <task_user.h>
#include <task_load_cell.h>
#include <taskshare.h>         
#include <taskqueue.h>
#include <shares.h>

//initialize shares
Share<float> current_position ("Position");
Queue<float> current_weight (100, "Weight");
<<<<<<< HEAD
Share<bool> initialized("initalized");
Share<float> user_position("input position");
Share<bool> inst_received("instructions recieved");
Share<bool> carousel_position("carousel desired position met?");
=======
Share<bool> initalized("initalized");
Queue<float> user_position(100, "input position");
Queue<float> desired_position(100, "input position");
Queue<float> desired_weight(100, "input position");
Share<bool> inst_recieved("instruction recieved");
Share<bool> carousel_position("carousel desired position");
>>>>>>> ae6b0be9091e1b6bfcc0a93abd9bf73160a8831f
Share<bool> zero("zero the carousel");
Share<bool> encoder_flag("tells encoder to read");
Share<bool> close_flag("tells to close the dispenser");
Share<bool> disp_flag("tells when to release");

/** @brief   The Arduino setup function.
 *  @details This function is used to set up the serial port and tasks. This function also was used to
 *           pass in the user data for testing.
 */
void setup() 
{
    user_position.put(200); //sets the required position, the value is 100x the desired index
    inst_received.put(true); //sets the flag that says data was sent to true

    Serial.begin (115200); //begins Serial readings
    while (!Serial)
    {
    }

<<<<<<< HEAD
    //creates each different task
    xTaskCreate (task_encoder, "Encoder", 5120, NULL, 6, NULL);
    xTaskCreate (task_carousel, "Carousel Motor", 5120, NULL, 4, NULL);
    xTaskCreate (task_door, "Door Motor", 5120, NULL, 3, NULL);
    //the load cell task is commented out because the load cell is broken
    //xTaskCreate (task_load_cell, "Load Cell", 5120, NULL, 5, NULL);
    xTaskCreate (task_opening, "Opening Motor", 5120, NULL, 2, NULL);
=======
    xTaskCreate (task_user, "Encoder", 5120, NULL, 6, NULL);
    //xTaskCreate (task_encoder, "Encoder", 5120, NULL, 6, NULL);
    //xTaskCreate (task_carousel, "Carousel Motor", 5120, NULL, 4, NULL);
    //xTaskCreate (task_door, "Door Motor", 5120, NULL, 3, NULL);
    // xTaskCreate (task_load_cell, "Load Cell", 5120, NULL, 5, NULL);
    // xTaskCreate (task_opening, "Carousel Motor", 5120, NULL, 2, NULL);
    // xTaskCreate (FSM, "Finite State Machine", 5120, NULL, 1, NULL);
>>>>>>> ae6b0be9091e1b6bfcc0a93abd9bf73160a8831f

}

/** @brief   The Arduino loop function.
 *  @details This function doesn't really do much at all.
 */
void loop() 
{

    vTaskDelay(50000);
  
}

