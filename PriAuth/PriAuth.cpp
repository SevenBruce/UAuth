/*
*   168 bit Elliptic Curve Diffie-Hellman
*
*   Requires: big.cpp ecn.cpp
*/
#include "PriAuth.h"


int main()
{
	time_t seed;
	Big a, b, p, q, x, y;
	ECn g;
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
	Gateway gateWay(g);

	//user initiation and registration at gateway.
	User aUser;
	RegUser regUser = aUser.generateReg();
	BackUser backUser = gateWay.getRegUser(regUser);
	aUser.getBackUser(backUser);

	//sensor initiation and registration at gateaway
	Sensor aSensor;
	RegSensor regSensor = aSensor.generateRegSensor();
	BackSensor backSensor = gateWay.getRegSensor(regSensor);
	aSensor.getBackSensor(backSensor);

	////authentication and key establishment phase
	aUser.setSidj(aSensor.getSidj());

	int round = 7;
	int times = 1;

	for (int j = 1; j <= round; j++) {
		times = 100 * j;
		cout << "the time of running PriAuth " << times << " times is :: " << endl;
		clock_t clock1 = clock();
		for (int i = 0; i < times; i++) {
			Message1 m1 = aUser.generateM1();
			Message2 m2 = aSensor.getM1(m1);
			Message3 m3 = gateWay.getM2(m2);
			Message4 m4 = aSensor.getM3(m3);
			aUser.getM4(m4);
		}
		clock_t clock2 = clock();
		cout << diffclock(clock1, clock2) << " ms " << endl;
	}


	system("PAUSE");
	return 0;

}




