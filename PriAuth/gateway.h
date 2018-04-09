#ifndef GATEWAY_H
#define GATEWAY_H

#include "utils.h"
#include "messages.h"
#include <string>
#include<iostream>
#include <vector>
using namespace std;
typedef std::vector<string> identiy_vector;

#include "ECn.h"
#include "Big.h"

#include "PublicPara.h"

class Gateway {
public:
	Gateway(ECn g);
	~Gateway() {
	}
	ECn getG();
	BackUser getRegUser(RegUser regUser);
	BackSensor getRegSensor(RegSensor regSensor);
	Message3 getM2(Message2 m2);
	bool Gateway::isInIdentieis(string idenity);
	void clearIdentities();

private:
	string xgwn;
	string idi;
	string sidj;

	ECn g;
	identiy_vector identities;
	ECn publicKey;
	Big privateKey;
};

#endif