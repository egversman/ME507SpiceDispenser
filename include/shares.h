/** @file shares.h
 *  This is the header file that contains the shared variables.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

//Data Shares 
<<<<<<< HEAD
extern Share<float> user_position;  //encoder position
=======
extern Queue<float> user_position;
extern Queue<float> user_weight;
>>>>>>> ae6b0be9091e1b6bfcc0a93abd9bf73160a8831f
//end

extern Queue<float> desired_position;
extern Queue<float> desired_weight;

extern Share<bool> door_open;

//Initialized Flags
extern Share<bool> initialized;

// Carousel Flags
extern Share<bool> inst_received;
extern Share<bool> carousel_position;
extern Share<bool> zero;

//Encoder Shares
extern Share<bool> encoder_flag;

// Close Flags
extern Share<bool> close_flag;
extern Share<bool> disp_flag;