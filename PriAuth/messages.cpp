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
}
BackUser::BackUser(string fi, ECn g, ECn gatePublicKey)
{
	BackUser::fi = fi;
	BackUser::g = g;
	BackUser::gatePublicKey = gatePublicKey;
}


string BackUser::getFi()
{
	return BackUser::fi;
}

void BackUser::setFi(string fi)
{
	BackUser::fi = fi;
}

ECn BackUser::getGatePublicKey()
{
	return BackUser::gatePublicKey;
}

void BackUser::setGatePublicKey(ECn gatePublicKey)
{
	BackUser::gatePublicKey = gatePublicKey;
}

ECn BackUser::getG()
{
	return BackUser::g;
}

void BackUser::setG(ECn g)
{
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
RegSensor::RegSensor(string sidj, string mnj, string mpj, int t1) {
	RegSensor::sidj = sidj;
	RegSensor::mnj = mnj;
	RegSensor::mpj = mpj;
	RegSensor::t1 = t1;
}
string RegSensor::getSidj() {
	return RegSensor::sidj;
}
void RegSensor::setSidj(string sidj) {
	RegSensor::sidj = sidj;
}

string RegSensor::getMpj() {
	return RegSensor::mpj;
}
void RegSensor::setMpj(string mpj) {
	RegSensor::mpj = mpj;
}
string RegSensor::getMnj() {
	return RegSensor::mnj;
}
void RegSensor::setMnj(string mnj) {
	RegSensor::mnj = mnj;
}
int RegSensor::getT1() {
	return RegSensor::t1;
}
void RegSensor::setT1(int t1) {
	RegSensor::t1 = t1;
}
#pragma endregion

#pragma region BackSensor
BackSensor::BackSensor()
{
}
BackSensor::BackSensor(string xj)
{
	BackSensor::ej = xj;
}
BackSensor::BackSensor(string xj, string fj, ECn g,int t2)
{
	BackSensor::ej = xj;
	BackSensor::fj = fj;
	BackSensor::g = g;
	BackSensor::t2 = t2;
}

string BackSensor::getEj() {
	return BackSensor::ej;
}
void BackSensor::setEj(string ej) {
	BackSensor::ej = ej;
}
string BackSensor::getFj() {
	return BackSensor::fj;
}
void BackSensor::setFj(string fj) {
	BackSensor::fj = fj;
}

int BackSensor::getT2() {
	return BackSensor::t2;
}
void BackSensor::setT2(int t2) {
	BackSensor::t2 = t2;
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
Message1::Message1(ECn a, string m1, string m2, int t1)
{
	Message1::A = a;
	Message1::m1 = m1;
	Message1::m2 = m2;	
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

string Message1::getM2()
{
	return Message1::m2;
}

void Message1::setM2(string m2)
{
	Message1::m2 = m2;
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
Message2::Message2(Message1 message1, ECn b, string m3, int t2)
{
	Message2::message1 = message1;
	Message2::B = b;
	Message2::m3 = m3;
	Message2::t2 = t2;
}

ECn Message2::getB()
{
	return Message2::B;
}
void Message2::setB(ECn b)
{
	Message2::B = b;
}

string Message2::getM3()
{
	return Message2::m3;
}

void Message2::setM3(string m3)
{
	Message2::m3 = m3;
}

Message1 Message2::getMessage1()
{
	return Message2::message1;
}

void Message2::setMessage1(Message1 message1)
{
	Message2::message1 = message1;
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
Message3::Message3(string m4, string m5)
{
	Message3::m4 = m4;
	Message3::m5 = m5;
}

string Message3::getM4() {
	return Message3::m4;
}

string Message3::getM5() {
	return Message3::m5;
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
Message4::Message4(ECn b, string m5)
{
	Message4::B = b;
	Message4::m5 = m5;
}
ECn Message4::getB() {
	return Message4::B;
}
string Message4::getM5() {
	return Message4::m5;
}
void Message4::setB(ECn b) {
	Message4::B = b;
}
void Message4::setM5(string m5) {
	Message4::m5 = m5;
}
#pragma endregion




