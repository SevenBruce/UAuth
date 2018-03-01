#ifndef USER_H
#define USER_H

#include "utils.h"
#include "messages.h"
#include "PublicPara.h"

#include <string>
#include<iostream>

using namespace std;

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
	string ri;
	string mpi;

	string fi;
	ECn g;
	ECn gatewayPublicKey;

	string sidj;
	int iUser;
	Big pUser;
	string m2m2;
	Big k1;
	ECn A;
	int timeStamp;

	string di;
	string skij;

};
#endif

