#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
	public:
		RegUser();
		RegUser::RegUser(string idi, string mpi, string mii);
		~RegUser()
		{

		}
		string getIdi();
		void setIdi(string idi);
		string getMpi();
		void setMpi(string mpi);
		string getMii();
		void setMii(string mii);
	
	private:
		string idi;
		string mpi;
		string mii;
};

class BackUser {
	public:
		BackUser();
		BackUser(string ei, string fi, ECn g);
		~BackUser()
		{

		}
		string getFi();
		void setFi(string fi);

		string getEi();
		void setEi(string ei);

		ECn getG();
		void setG(ECn g);
	private:
		string fi;
		string ei;
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
	BackSensor(string cj, ECn g);
	~BackSensor(){}
	string getCj();
	void setCj(string cj);

	ECn getG();
	void setG(ECn g);
private:
	string cj;
	ECn g;
};

class Message1 {
	public:
		Message1();
		Message1(string mii, string sidj, string b1, ECn b2, string b3, string b4, string b5);
		~Message1()
		{
		}
		
		string getMii();
		string getSidj();
		string getB1();
		ECn getB2();
		string getB3();
		string getB4();
		string getB5();

		
		void setMii(string ki);
		void setSidj(string m1);
		void setB1(string b1);
		void setB2(ECn b2);
		void setB3(string b3);
		void setB4(string b4);
		void setB5(string b5);

	private:
		
		string mii;
		string sidj;
		string b1;
		string b3;
		ECn b2;
		string b4;
		string b5;
};

class Message2 {
public:
	Message2();
	Message2(string mii, string sidj, ECn B, string d1);
	~Message2()
	{

	}
	ECn getB2();
	string getMii();
	string getSidj();
	string getD1();

	void setB2(ECn a);
	void setMii(string ki);
	void setD1(string d1);
	void setSidj(string sidj);

private:
	ECn B2;
	string mii;
	string sidj;
	string d1;
};

class Message3 {
public:
	Message3();
	Message3(ECn c1,string m4,string m5);
	~Message3()	{}
	ECn getC1();
	string getC3();
	string getC4();
	void setC1(ECn c1);
	void setC3(string c3);
	void setC4(string c4);
private:
	ECn C1;
	string c3;
	string c4;	
};

class Message4 {
public:
	Message4();
	Message4(ECn c1, string c3, string d2, string d3, string d4);
	~Message4()	{}
	ECn getC1();
	string getC3();
	string getD2();
	string getD3();
	string getD4();

	void setC1(ECn c1);
	void setC3(string c3);
	void setD2(string d2);
	void setD3(string d3);
	void setD4(string d4);
private:
	ECn C1;
	string c3;
	string d2;
	string d3;
	string d4;
};

#endif
