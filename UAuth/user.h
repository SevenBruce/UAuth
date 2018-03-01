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
	Message1 generateM1()
	{
		User::di = xor (User::fi, User::mpi);
		User::ei = xor (User::li, User::mpi);

		User::k1 = rand(160, 2);
		//cout << "k1:" << k1 << endl;
		User::A = User::g;
		User::A *= User::k1;

		User::timeStamp = time(NULL);
		string m2m2 = hashSha256(ecn2String(User::A) + User::idi + User::sidj + User::di + std::to_string(User::timeStamp));
		string m1m1 = xor ((User::idi + User::sidj + m2m2), ei);

		Message1 message1(User::A, User::ki, m1m1, User::timeStamp);
		return message1;
	}
	void getM4(Message4 m4);

private:
	string idi;
	string pwi;
	string ri;
	string mpi;

	string fi;
	string li;
	string ki;
	ECn g;

	string sidj;
	int iUser;
	Big pUser;
	Big k1;
	ECn A;
	int timeStamp;

	string ei;
	string di;
	string skij;

};
#pragma endregion

