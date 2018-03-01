#include "uAuth.h"

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
	//User aUser(gateWay.getG());
	User aUser;
	RegUser regUser = aUser.generateReg();
	BackUser backUser = gateWay.getRegUser(regUser);
	aUser.getBackUser(backUser);

	//sensor initiation and registration at gateaway
	//Sensor aSensor(gateWay.getG());
	Sensor aSensor;
	RegSensor regSensor = aSensor.generateRegSensor();
	BackSensor backSensor = gateWay.getRegSensor(regSensor);
	aSensor.getBackSensor(backSensor);

	//authentication and key establishment phase
	aUser.setSidj(aSensor.getSidj());
	cout << "ECn:" << sizeof(ECn) << endl;
	cout << "int:" << sizeof(int) << endl;
	cout << "char:" << sizeof(char) << endl;
	cout << "g:" << sizeof(g) << endl;
	cout << "Big:" << sizeof(Big) << endl;
	cout << "big:" << sizeof(big) << endl;
	cout << "a:" << sizeof(a) << endl; 
	cout << "&a:" << sizeof(&a) << endl;
	cout << "epoint:" << sizeof(epoint) << endl;

	ECn temKey = g;
	Big k1 = rand(160,2);
	temKey *= k1;
	Big key;
	temKey.get(key);
	cout << "ECn:" << sizeof(temKey) << endl;
	cout << "Big:" << sizeof(key) << endl;
	int round = 7;
	int times = 1;

	for (int j = 1; j <= round; j++) {
		times = 100 * j;
		cout << "the time of running UAuth " << times << " times is :: " << endl;
		clock_t clock1 = clock();
		for (int i = 0; i < times; i++) {
			Message1 m1 = aUser.generateM1();
			Message2 m2 = gateWay.getM1(m1);
			Message3 m3 = aSensor.getM2(m2);
			Message4 m4 = gateWay.getM3(m3);
			aUser.getM4(m4);
		}
		clock_t clock2 = clock();
		cout << "different:: " << diffclock(clock1, clock2) << endl;
	}

	system("PAUSE");
	return 0;

}




