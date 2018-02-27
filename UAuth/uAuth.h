#ifndef UAUTH_H
#define UAUTH_H
#endif

/*
*   168 bit Elliptic Curve Diffie-Hellman
*
*   Requires: big.cpp ecn.cpp
*/

#include <iostream>
using namespace std;
#include <string>
#include "ecn.h"
#include "big.h"
#include "utils.h"
#include "sensor.h"
#include "gateway.h"
#include "user.h"
#include "messages.h"

#ifndef MR_NOFULLWIDTH
Miracl precision(50, 0);
#else 
Miracl precision(50, MAXBASE);
#endif

#pragma once
