#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
	public:
		RegUser();
		RegUser::RegUser(string idi, string hpwi);
		~RegUser()
		{

		}
		string getIdi();
		void setIdi(string idi);
		string getHpwi();
		void setHpwi(string hpwi);
	
	private:
		string idi;
		string hpwi;
};

class BackUser {
	public:
		BackUser();
		BackUser(string ai, string ei, string fi, ECn g);
		~BackUser()
		{

		}
		string getAi();
		void setAi(string ai);

		string getB1();
		void setB1(string b1);

		string getB2();
		void setB2(string b2);

		ECn getG();
		void setG(ECn g);
	private:
		string ai;
		string b1;
		string b2;
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
	BackSensor(string b4);
	~BackSensor(){}
	string getB4();
	void setB4(string b4);

private:
	string b4;
};

class Message1 {
	public:
		Message1();
		Message1(string c2, ECn c3, string c5, string ai);
		~Message1()
		{
		}
		

		string getC2();
		ECn getC3();
		string getC5();
		string getAi();

	
		void setC2(string b1);
		void setC3(ECn b2);
		void setC5(string b4);
		void setAi(string b5);

	private:
		
		string c2;
		ECn c3;
		string c5;
		string ai;
};

class Message2 {
public:
	Message2();
	Message2(ECn B, string d1);
	~Message2()
	{

	}
	ECn getC3();
	string getC7();

	void setC3(ECn c3);
	void setC7(string c7);

private:
	ECn c3;
	string c7;
};

class Message3 {
public:
	Message3();
	Message3(ECn c8,string c10,string c11);
	~Message3()	{}
	ECn getC8();
	string getC10();
	string getC11();
	void setC8(ECn c8);
	void setC10(string c10);
	void setC11(string c11);
private:
	ECn c8;
	string c10;
	string c11;	
};

class Message4 {
public:
	Message4();
	Message4(ECn c8, string c10, string c12, string c13, string c14);
	~Message4()	{}
	ECn getC8();
	string getC10();
	string getC12();
	string getC13();
	string getC14();

	void setC8(ECn c8);
	void setC10(string c10);
	void setC12(string c12);
	void setC13(string c13);
	void setC14(string c14);
private:
	ECn c8;
	string c10;
	string c12;
	string c13;
	string c14;
};

#endif
