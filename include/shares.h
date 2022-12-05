#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

//Data Shares 
extern Share<float> user_position;  //encoder position
//end

extern Share<bool> door_open;

//Initialized Flags
extern Share<bool> initalized;

// Carousel Flags
extern Share<bool> inst_recieved;
extern Share<bool> carousel_position;
extern Share<bool> zero;

//Encoder Shares
extern Share<bool> encoder_flag;

// Close Flags
extern Share<bool> close_flag;
extern Share<bool> disp_flag;