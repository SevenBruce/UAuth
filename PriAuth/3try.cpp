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
#include "entities.h"
#include "messages.h"

#ifndef MR_NOFULLWIDTH
Miracl precision(50, 0);
#else 
Miracl precision(50, MAXBASE);
#endif

int main()
{
	int ia, ib;
	time_t seed;
	Big a, b, p, q, n, phi, pa, pb, key, e, d, m, c, x, y, k, inv, t;
	Big primes[2], pm[2];
	ECn g, ea, eb;
	miracl *mip = &precision;

	time(&seed);
	irand((long)seed);   /* change parameter for different values */
	a = -3;
	mip->IOBASE = 16;
	b = ecb_user_define;
	p = ecp_user_define;
	ecurve(a, b, p, MR_BEST);  // means use PROJECTIVE if possible, else AFFINE coordinates
	x = ecx_user_define;
	y = ecy_user_define;
	mip->IOBASE = 10;
	g = ECn(x, y);

	//gateway initiation;
	Gateway gateWay;

	//user initiation and registration at gateway.
	//User aUser(gateWay.getG());
	User aUser(g);
	RegUser regUser = aUser.generateReg();
	BackUser backUser = gateWay.getRegUser(regUser);
	aUser.getBackUser(backUser);

	//sensor initiation and registration at gateaway
	//Sensor aSensor(gateWay.getG());
	Sensor aSensor(g);
	RegSensor regSensor = aSensor.generateRegSensor();
	BackSensor backSensor = gateWay.getRegSensor(regSensor);
	aSensor.getBackSensor(backSensor);

	//authentication and key establishment phase
	aUser.setSidj(aSensor.getSidj());
	Message1 m1 = aUser.generateM1();
	Message2 m2 = gateWay.getM1(m1);
	Message3 m3 = aSensor.getM2(m2);
	Message4 m4 = gateWay.getM3(m3);
	aUser.getM4(m4);
	
	system("PAUSE");
	return 0;

}


 

