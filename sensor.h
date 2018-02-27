#ifndef SENSOR_H
#define SENSOR_H

#include "utils.h"
#include "messages.h"
#include "publicPara.h"

#include <time.h>
#include "ecn.h"
#include "big.h"

#include<iostream>
#include <string>
using namespace std;

#pragma region Sensor
class Sensor {
public:
	Sensor();
	~Sensor() {
	}
	RegSensor generateRegSensor();
	void getBackSensor(BackSensor backSensor);
	Message3 getM2(Message2 m2);
	string getSidj();

private:
	string sidj;
	string xj;
	string skij;
	ECn g;
	Big k2;

	ECn B;
	int timeStamp;
};
#pragma endregion




#endif


