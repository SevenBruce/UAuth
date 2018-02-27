#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
public:
	RegUser();
	~RegUser()
	{

	}
	string getIdi();
	void setIdi(string idi);

	string getMpi();
	void RegUser::ShowMpi();
	void setMpi(string mpi);

private:
	string idi;
	string mpi;
};

class BackUser {
public:
	BackUser();
	BackUser(string fi, string li, string ki, ECn g);
	~BackUser()
	{

	}
	string getFi();
	void setFi(string fi);

	string getLi();
	void setLi(string li);

	string getKi();
	void setKi(string ki);

	ECn getG();
	void setG(ECn g);
private:
	string fi;
	string li;
	string ki;
	ECn g;
};

class RegSensor {
public:
	RegSensor();
	RegSensor(string sidj);
	~RegSensor()
	{

	}
	string getSidj();
	void setSidj(string sidj);

private:
	string sidj;
};

class BackSensor {
public:
	BackSensor();
	BackSensor(string xj, ECn g);
	~BackSensor() {}
	string getXj();
	void setXj(string xj);
	ECn getG();
	void setG(ECn g);

private:
	string xj;
	ECn g;
};

class Message1 {
public:
	Message1();
	Message1(ECn a, string ki, string m1, int t1);
	~Message1()
	{
	}
	ECn getA();
	string getKi();
	string getM1();
	int getT1();

	void setA(ECn a);
	void setKi(string ki);
	void setM1(string m1);
	void setT1(int t1);

private:
	ECn A;
	string ki;
	string m1;
	time_t t1;
};

class Message2 {
public:
	Message2();
	Message2(ECn A, string m3, int t2);
	~Message2()
	{

	}
	ECn getA();
	string getM3();
	int getT2();

	void setA(ECn a);
	void setM3(string ki);
	void setT2(int t2);
private:
	ECn A;
	string m3;
	int t2;


};

class Message3 {
public:
	Message3();
	Message3(ECn b, string m4, string m5);
	~Message3() {}
	ECn getB();
	string getM4();
	string getM5();
	void setB(ECn b);
	void setM4(string m4);
	void setM5(string m5);
private:
	ECn B;
	string m4;
	string m5;
};

class Message4 {
public:
	Message4();
	Message4(ECn b, string m6);
	~Message4() {}
	ECn getB();
	string getM6();
	void setB(ECn b);
	void setM6(string m6);
private:
	ECn B;
	string m6;
};

#endif
