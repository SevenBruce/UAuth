#ifndef GATEWAY_H
#define GATEWAY_H
#endif

#include "utils.h"
#include "messages.h"
#include "publicPara.h"

#include <time.h>
#include "ecn.h"
#include "big.h"

#include<iostream>
#include <string>
#include <vector>
using namespace std;
typedef std::vector<string> identiy_vector;

#pragma region Gateway
class Gateway {
public:
	Gateway(ECn g);
	~Gateway() {
	}
	ECn getG();
	BackUser getRegUser(RegUser regUser);
	BackSensor getRegSensor(RegSensor regSensor);
	bool Gateway::isInIdentieis(string idenity);
	void clearIdentities();
	Message2 getM1(Message1 m1);
	Message4 getM3(Message3 m3);

private:
	string x;
	string idgwn;
	string r1;
	string ai;

	string idi;
	string sidj;
	string b4;

	ECn g;
	identiy_vector identities;
	ECn C3;
};
#pragma endregion