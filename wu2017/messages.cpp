#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
	RegUser::idi = "";
	RegUser::hpwi = "";
}

RegUser::RegUser(string idi,string hpwi)
{
	RegUser::idi = idi;
	RegUser::hpwi = hpwi;
}

string RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(string idi)
{
	RegUser::idi = idi;
}

string RegUser::getHpwi()
{
	return RegUser::hpwi;
}

void RegUser::setHpwi(string mpi)
{
	RegUser::hpwi = mpi;
}

#pragma endregion

#pragma region BackUser

BackUser::BackUser()
{
}

BackUser::BackUser(string ai, string b1, string b2, ECn g) {
	BackUser::ai = ai;
	BackUser::b1 = b1;
	BackUser::b2 = b2;
	BackUser::g = g;
}
string BackUser::getAi() {
	return BackUser::ai;
}
void BackUser::setAi(string ai) {
	BackUser::ai = ai;
}

string BackUser::getB1()
{
	return BackUser::b1;
}

void BackUser::setB1(string fi)
{
	BackUser::b1 = fi;
}

string BackUser::getB2() {
	return BackUser::b2;
}
void BackUser::setB2(string ei) {
	BackUser::b2 = ei;
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
BackSensor::BackSensor(string b4, ECn g)
{
	BackSensor::b4 = b4;
	BackSensor::g = g;

}
string BackSensor::getB4() {
	return BackSensor::b4;
}
void BackSensor::setB4(string cj) {
	BackSensor::b4 = cj;
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
Message1::Message1(string c2, ECn c3, string c5, string ai)
{
	Message1::c2 = c2;
	Message1::c3 = c3;
	Message1::c5 = c5;
	Message1::ai = ai;
}
ECn Message1::getC3()
{
	return Message1::c3;
}
void Message1::setC3(ECn c3)
{
	Message1::c3 = c3;
}

string Message1::getC2() {
	return Message1::c2;
}

void Message1::setC2(string c2) {
	Message1::c2 = c2;
}

string Message1::getC5() {
	return Message1::c5;
}
void Message1::setC5(string c5) {
	Message1::c5 = c5;
}
string Message1::getAi() {
	return Message1::ai;
}
void Message1::setAi(string ai) {
	Message1::ai = ai;
}

#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(ECn c3, string c7)
{
	Message2::c3 = c3;
	Message2::c7 = c7;
}

ECn Message2::getC3()
{
	return Message2::c3;
}
void Message2::setC3(ECn C3)
{
	Message2::c3 = C3;
}


string Message2::getC7()
{
	return Message2::c7;
}

void Message2::setC7(string c7)
{
	Message2::c7 = c7;
}

#pragma endregion



#pragma region Message333
Message3::Message3()
{
}
Message3::Message3(ECn c8, string c10, string c11)
{
	Message3::c8 = c8;
	Message3::c10 = c10;
	Message3::c11 = c11;
}

ECn Message3::getC8() {
	return Message3::c8;
}
string Message3::getC10() {
	return Message3::c10;
}

string Message3::getC11() {
	return Message3::c11;
}

void Message3::setC8(ECn c1) {
	Message3::c8 = c1;
}
void Message3::setC10(string c10) {
	Message3::c10 = c10;
}
void Message3::setC11(string c11) {
	Message3::c11 = c11;
}
#pragma endregion


#pragma region Message4
Message4::Message4()
{
}
Message4::Message4(ECn c8, string c10, string c12, string c13, string c14)
{
	Message4::c8 = c8;
	Message4::c10 = c10;
	Message4::c12 = c12;
	Message4::c13 = c13;
	Message4::c14 = c14;
}
ECn Message4::getC8() {
	return Message4::c8;
}
string Message4::getC10() {
	return Message4::c10;
}
string Message4::getC12() {
	return Message4::c12;
}
string Message4::getC13() {
	return Message4::c13;
}
string Message4::getC14() {
	return Message4::c14;
}
void Message4::setC8(ECn c8) {
	Message4::c8 = c8;
}
void Message4::setC10(string c10) {
	Message4::c10 = c10;
}
void Message4::setC12(string c12) {
	Message4::c12 = c12;
}
void Message4::setC13(string c13) {
	Message4::c13 = c13;
}
void Message4::setC14(string c14) {
	Message4::c14 = c14;
}
#pragma endregion




