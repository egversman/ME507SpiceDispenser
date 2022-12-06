#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

//Data Shares 
extern Queue<float> user_position;
extern Queue<float> user_weight;
//end

extern Queue<float> desired_position;
extern Queue<float> desired_weight;

extern Share<bool> door_open;

//Initialized Flags
extern Share<bool> initalized;

// Carosell Flags
extern Share<bool> inst_recieved;
extern Share<bool> carousel_position;
extern Share<bool> zero;

// 