#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
	public:
		RegUser();
		RegUser(string idi, string mpi);
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
		BackUser::BackUser(string fi, ECn g, ECn gatePublicKey);
		~BackUser()
		{

		}
		string getFi();
		void setFi(string fi);

		ECn getG();
		void setG(ECn g);

		ECn getGatePublicKey();
		void setGatePublicKey(ECn gatePublicKey);

	private:
		ECn g;
		string fi;
		ECn gatePublicKey;
};

class RegSensor {
public:
	RegSensor();
	RegSensor(string sidj);
	RegSensor(string sidj, string mnj, string mpj, int t1);
	~RegSensor()
	{

	}
	string getSidj();
	void setSidj(string sidj);
	string getMpj();
	void setMpj(string sidj);
	string getMnj();
	void setMnj(string mnj);
	int getT1();
	void setT1(int t1);

private:
	string sidj;
	string mnj;
	string mpj;
	int t1;
};

class BackSensor {
public:
	BackSensor();
	BackSensor(string ej);
	BackSensor(string ej,string fj, ECn g,int t2);
	~BackSensor(){}
	string getEj();
	void setEj(string ej);
	string getFj();
	void setFj(string fj);
	int getT2();
	void setT2(int t2);
	ECn getG();
	void setG(ECn g);

private:
	string ej;
	string fj;
	ECn g;
	int t2;
};

class Message1 {
	public:
		Message1();
		Message1(ECn a,string m1, string m2,int t1);
		~Message1()
		{
		}
		ECn getA();
		string getM1();
		string getM2();
		int getT1();

		void setA(ECn a);
		void setM1(string m1);
		void setM2(string m2);
		void setT1(int t1);

	private:
		ECn A;		
		string m1;
		string m2;
		time_t t1;
};

class Message2 {
public:
	Message2();
	Message2(Message1 message1, ECn B, string m3,int t2);
	~Message2()
	{

	}
	Message1 getMessage1();
	ECn getB();
	string getM3();
	int getT2();

	void setMessage1(Message1 message1);
	void setB(ECn a);
	void setM3(string ki);
	void setT2(int t2);
private:
	Message1 message1;
	ECn B;
	string m3;
	int t2;


};

class Message3 {
public:
	Message3();
	Message3(string m4,string m5);
	~Message3()	{}
	string getM4();
	string getM5();
	void setM4(string m4);
	void setM5(string m5);
private:
	string m4;
	string m5;	
};

class Message4 {
public:
	Message4();
	Message4(ECn b, string m5);
	~Message4()	{}
	ECn getB();
	string getM5();
	void setB(ECn b);
	void setM5(string m5);
private:
	ECn B;
	string m5;	
};

#endif
