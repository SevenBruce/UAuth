#ifndef USER_H
#define USER_H
#endif

#include "utils.h"
#include "messages.h"
#include "publicPara.h"

#include <time.h>
#include "ecn.h"
#include "big.h"

#include<iostream>
#include <string>
using namespace std;

#pragma region User
class User {
public:
	User();
	~User() {
	}
	RegUser generateReg();
	void getBackUser(BackUser backUser);
	void setSidj(string sidj);
	Message1 generateM1();
	void getM4(Message4 m4);

private:
	string idi;
	string pwi;
	string bi;
	string hpwi;


	string r1;

	string ai;
	string b1;
	string b2;
	string b3;
	ECn g;

	string sidj;
	int iUser;
	Big pUser;
	Big alpha;
	ECn C3;
	
	string sku;
};
#pragma endregion

