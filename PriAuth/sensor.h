#ifndef SENSOR_H
#define SENSOR_H

#include "utils.h"
#include "messages.h"
#include "PublicPara.h"

#include <string>
#include<iostream>
using namespace std;

class Sensor {
public:
	Sensor();
	~Sensor() {
	}
	RegSensor generateRegSensor();
	void getBackSensor(BackSensor backSensor);
	Message2 Sensor::getM1(Message1 m1);
	Message4 getM3(Message3 m3);
	string getSidj();

private:
	string sidj;
	string xj;
	string skij;

	string m3m3;

	ECn g;
	Big k2;
	string xgwn_sj;

	ECn B;
	ECn A;
	int timeStamp2;
};


#endif // !SENSOR
