#ifndef PRIAUTH_H
#define PRIAUTH_H

#include <iostream>
using namespace std;
#include <string>
#include "ecn.h"
#include "big.h"
#include "utils.h"
//#include "entities.h"
#include "gateway.h"
#include "user.h"
#include "sensor.h"
#include "messages.h"

#ifndef MR_NOFULLWIDTH
Miracl precision(50, 0);
#else 
Miracl precision(50, MAXBASE);
#endif


#endif

