#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
	RegUser::idi = "";
	RegUser::mpi = "";
}

string RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(string idi)
{
	RegUser::idi = idi;
}

string RegUser::getMpi()
{
	return RegUser::mpi;
}

void RegUser::ShowMpi()
{
	int i;
	for (i = 0; i < 32; i++) printf("%02x", (unsigned char)RegUser::mpi[i]);
	printf("\n");
}

void RegUser::setMpi(string mpi)
{
	RegUser::mpi = mpi;
}
#pragma endregion

#pragma region BackUser
BackUser::BackUser()
{
	BackUser::fi = "";
	BackUser::li = "";
	BackUser::ki = "";
}

BackUser::BackUser(string fi, string li, string ki, ECn g)
{
	BackUser::fi = fi;
	BackUser::li = li;
	BackUser::ki = ki;
	BackUser::g = g;
}

string BackUser::getFi()
{
	return BackUser::fi;
}

void BackUser::setFi(string fi)
{
	BackUser::fi = fi;
}

string BackUser::getLi()
{
	return BackUser::li;
}

void BackUser::setLi(string li)
{
	BackUser::li = li;
}

string BackUser::getKi()
{
	return BackUser::ki;
}

void BackUser::setKi(string ki)
{
	BackUser::ki = ki;
}

ECn BackUser::getG() {
	return BackUser::g;
}
void BackUser::setG(ECn g) {
	BackUser::g = g;
}

#pragma endregion

#pragma region RegSensor
RegSensor::RegSensor()
{
}
RegSensor::RegSensor(string sidj)
{
	RegSensor::sidj = sidj;
}
string RegSensor::getSidj() {
	return RegSensor::sidj;
}
void RegSensor::setSidj(string sidj) {
	RegSensor::sidj = sidj;
}
#pragma endregion

#pragma region BackSensor
BackSensor::BackSensor()
{
}
BackSensor::BackSensor(string xj, ECn g)
{
	BackSensor::xj = xj;
	BackSensor::g = g;
}
string BackSensor::getXj() {
	return BackSensor::xj;
}
void BackSensor::setXj(string xj) {
	BackSensor::xj = xj;
}

ECn BackSensor::getG() {
	return BackSensor::g;
}
void BackSensor::setG(ECn g) {
	BackSensor::g = g;
}
#pragma endregion


#pragma region M1
Message1::Message1()
{
}
Message1::Message1(ECn a, string ki, string m1, int t1)
{
	Message1::A = a;
	Message1::ki = ki;
	Message1::m1 = m1;
	Message1::t1 = t1;
}
ECn Message1::getA()
{
	return Message1::A;
}
void Message1::setA(ECn a)
{
	Message1::A = a;
}

string Message1::getKi()
{
	return Message1::ki;
}

void Message1::setKi(string ki)
{
	Message1::ki = ki;
}

string Message1::getM1()
{
	return Message1::m1;
}

void Message1::setM1(string m1)
{
	Message1::m1 = m1;
}

int Message1::getT1()
{
	return Message1::t1;
}

void Message1::setT1(int t1)
{
	Message1::t1 = t1;
}

#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(ECn A, string m3, int t2)
{
	Message2::A = A;
	Message2::m3 = m3;
	Message2::t2 = t2;
}

ECn Message2::getA()
{
	return Message2::A;
}
void Message2::setA(ECn a)
{
	Message2::A = a;
}

string Message2::getM3()
{
	return Message2::m3;
}

void Message2::setM3(string m3)
{
	Message2::m3 = m3;
}

int Message2::getT2()
{
	return Message2::t2;
}

void Message2::setT2(int t2)
{
	Message2::t2 = t2;
}

#pragma endregion



#pragma region Message333
Message3::Message3()
{
}
Message3::Message3(ECn b, string m4, string m5)
{
	Message3::B = b;
	Message3::m4 = m4;
	Message3::m5 = m5;
}

ECn Message3::getB() {
	return Message3::B;
}
string Message3::getM4() {
	return Message3::m4;
}

string Message3::getM5() {
	return Message3::m5;
}

void Message3::setB(ECn b) {
	Message3::B = b;
}
void Message3::setM4(string m4) {
	Message3::m4 = m4;
}
void Message3::setM5(string m5) {
	Message3::m5 = m5;
}
#pragma endregion


#pragma region Message4
Message4::Message4()
{
}
Message4::Message4(ECn b, string m6)
{
	Message4::B = b;
	Message4::m6 = m6;
}
ECn Message4::getB() {
	return Message4::B;
}
string Message4::getM6() {
	return Message4::m6;
}
void Message4::setB(ECn b) {
	Message4::B = b;
}
void Message4::setM6(string m6) {
	Message4::m6 = m6;
}
#pragma endregion




