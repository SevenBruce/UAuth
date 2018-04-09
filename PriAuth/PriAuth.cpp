#include "PriAuth.h"

User arrayUser[1000];
Sensor *arraySensor = new Sensor[1000];
int times[5] = { 100, 250 , 500, 750 , 1000 };
//int times[5] = { 5, 10 , 15, 20 , 25 };
void sensorRegistrationTime(Gateway gateWay);
void userRegistrationTime(Gateway gateWay);
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


	int count = 10;
	clock_t clock1, clock2;
	double sum = 0;
	for (int j = 0; j < 5; j++) {
		cout << "the time of running PriAuth " << times[j] << " times is :: " << endl;
		for (int k = 0; k < count; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				Message1 m1 = aUser.generateM1();
				Message2 m2 = aSensor.getM1(m1);
				Message3 m3 = gateWay.getM2(m2);
				Message4 m4 = aSensor.getM3(m3);
				aUser.getM4(m4);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}
		}
		cout << "different:: " << sum / count << endl;
		sum = 0;
	}
	gateWay.clearIdentities();

	for (int i = 0; i < 1000; i++) {
		arraySensor[i] = Sensor();
	}

	userRegistrationTime(gateWay);
	sensorRegistrationTime(gateWay);

	system("PAUSE");
	return 0;

}


void userRegistrationTime(Gateway gateWay) {
	clock_t clock1, clock2;
	RegUser regUser;
	BackUser backUser;
	int count = 100;
	double sum = 0;

	for (int j = 0; j < 5; j++) {
		cout << "User registration time of running PriAuth " << times[j] << " times is :: " << endl;
		for (int k = 0; k < count; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				regUser = arrayUser[i].generateReg();
				backUser = gateWay.getRegUser(regUser);
				arrayUser[i].getBackUser(backUser);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}			
			//cout << "different:: " << diffclock(clock2, clock1) << endl;
			gateWay.clearIdentities();
		}
		cout << "different:: " << sum / count << endl;
		sum = 0;
	}

}

void sensorRegistrationTime(Gateway gateWay) {
	clock_t clock1, clock2;
	RegSensor regSensor;
	BackSensor backSensor;
	int count = 100;
	double sum = 0;

	for (int j = 0; j < 5; j++) {
		cout << "Sensor registration time of running PriAuth " << times[j] << " times is :: " << endl;
		for (int k = 0; k < count; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				regSensor = arraySensor[i].generateRegSensor();
				backSensor = gateWay.getRegSensor(regSensor);
				arraySensor[i].getBackSensor(backSensor);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}
		}
		cout << "different:: " << sum / count << endl;
		sum = 0;
	}
}




