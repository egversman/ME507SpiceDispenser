#ifndef _SHARES_H_
#define _SHARES_H_



#include "taskqueue.h"
#include "taskshare.h"


extern Queue<float> desired_weight;
extern Queue<float> desired_angle;
extern Share<float> weight;
extern Share<float> angle;


#endif // _SHARES_H_

