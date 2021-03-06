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
	string r3;
	string mii;
	string miiNew;

	string idi;
	string sidj;
	string cj;

	string m3;

	ECn g;
	identiy_vector identities;
	int timeStamp2;
	int timeStamp1;
};
#pragma endregion