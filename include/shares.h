#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

//Data Shares 
extern Share<float> user_position;
//end

extern Share<bool> door_open;

//Initialized Flags
extern Share<bool> initalized;

// Carosell Flags
extern Share<bool> inst_recieved;
extern Share<bool> carousel_position;
extern Share<bool> zero;

// 