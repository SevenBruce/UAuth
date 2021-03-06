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
	void sensorCheckIdentity(string sidj);
	string sidj;
	string cj;
	string sks;
	ECn g;
	Big beta;

	ECn C1;
};
#pragma endregion




#endif


