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
	string r0;
	string mpi;
	string mii;
	string miiNew;

	string r2;
	string r3;

	string fi;
	ECn g;

	string sidj;
	int iUser;
	Big pUser;
	Big alpha;
	ECn B2;
	int timeStamp;

	string ei;
	string di;
	string sku;

};
#pragma endregion

