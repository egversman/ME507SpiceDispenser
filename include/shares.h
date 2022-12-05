#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

//Data Shares 
extern Queue<float> user_position;
extern Queue<float> user_weight;
//end

extern Share<bool> door_open;

//Initialized Flags
extern Share<bool> initalized;

// Carousel Flags
extern Share<bool> inst_recieved;
extern Share<bool> carousel_position;
extern Share<bool> zero;

// 