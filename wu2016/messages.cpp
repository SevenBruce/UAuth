#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
	RegUser::idi = "";
	RegUser::mpi = "";
}

RegUser::RegUser(string idi,string mpi,string mii)
{
	RegUser::idi = idi;
	RegUser::mpi = mpi;
	RegUser::mii = mii;
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

void RegUser::setMpi(string mpi)
{
	RegUser::mpi = mpi;
}

string RegUser::getMii() {
	return RegUser::mii;
}
void RegUser::setMii(string mii) {
	RegUser::mii = mii;
}
#pragma endregion

#pragma region BackUser

BackUser::BackUser(string ei, string fi, ECn g) {
	BackUser::ei = ei;
	BackUser::fi = fi;
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

string BackUser::getEi() {
	return BackUser::ei;
}
void BackUser::setEi(string ei) {
	BackUser::ei = ei;
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
BackSensor::BackSensor(string cj, ECn g)
{
	BackSensor::cj = cj;
	BackSensor::g = g;
}
string BackSensor::getCj() {
	return BackSensor::cj;
}
void BackSensor::setCj(string cj) {
	BackSensor::cj = cj;
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
Message1::Message1(string mii, string sidj, string b1, ECn b2, string b3, string b4, string b5)
{
	Message1::mii = mii;
	Message1::sidj = sidj;
	Message1::b1 = b1;
	Message1::b2 = b2;
	Message1::b3 = b3;
	Message1::b4 = b4;
	Message1::b5 = b5;
}
ECn Message1::getB2()
{
	return Message1::b2;
}
void Message1::setB2(ECn a)
{
	Message1::b2 = a;
}

string Message1::getMii()
{
	return Message1::mii;
}

void Message1::setMii(string ki)
{
	Message1::mii = ki;
}

string Message1::getSidj()
{
	return Message1::sidj;
}

void Message1::setSidj(string m1)
{
	Message1::sidj = m1;
}
string Message1::getB1() {
	return Message1::b1;
}

void Message1::setB1(string b1) {
	Message1::b1 = b1;
}

string Message1::getB3() {
	return Message1::b3;
}
void Message1::setB3(string b3) {
	Message1::b3 = b3;
}
string Message1::getB4() {
	return Message1::b4;
}
void Message1::setB4(string b4) {
	Message1::b4 = b4;
}
string Message1::getB5() {
	return Message1::b5;
}
void Message1::setB5(string b5) {
	Message1::b5 = b5;
}

#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(string mii, string sidj, ECn B2, string d1)
{
	Message2::mii = mii;
	Message2::sidj = sidj;
	Message2::B2 = B2;
	Message2::d1 = d1;
}

ECn Message2::getB2()
{
	return Message2::B2;
}
void Message2::setB2(ECn b2)
{
	Message2::B2 = b2;
}

string Message2::getMii()
{
	return Message2::mii;
}

void Message2::setMii(string m3)
{
	Message2::mii = m3;
}

string Message2::getSidj()
{
	return Message2::sidj;
}

void Message2::setSidj(string sidj)
{
	Message2::sidj = sidj;
}

string Message2::getD1()
{
	return Message2::d1;
}

void Message2::setD1(string d1)
{
	Message2::sidj = d1;
}

#pragma endregion



#pragma region Message333
Message3::Message3()
{
}
Message3::Message3(ECn c1, string m4, string m5)
{
	Message3::C1 = c1;
	Message3::c3 = m4;
	Message3::c4 = m5;
}

ECn Message3::getC1() {
	return Message3::C1;
}
string Message3::getC3() {
	return Message3::c3;
}

string Message3::getC4() {
	return Message3::c4;
}

void Message3::setC1(ECn c1) {
	Message3::C1 = c1;
}
void Message3::setC3(string m4) {
	Message3::c3 = m4;
}
void Message3::setC4(string m5) {
	Message3::c4 = m5;
}
#pragma endregion


#pragma region Message4
Message4::Message4()
{
}
Message4::Message4(ECn c1, string c3, string d2, string d3, string d4)
{
	Message4::C1 = c1;
	Message4::c3 = c3;
	Message4::d2 = d2;
	Message4::d3 = d3;
	Message4::d4 = d4;
}
ECn Message4::getC1() {
	return Message4::C1;
}
string Message4::getC3() {
	return Message4::c3;
}
string Message4::getD2() {
	return Message4::d2;
}
string Message4::getD3() {
	return Message4::d3;
}
string Message4::getD4() {
	return Message4::d4;
}
void Message4::setC1(ECn b) {
	Message4::C1 = b;
}
void Message4::setC3(string m6) {
	Message4::c3 = m6;
}
void Message4::setD2(string d2) {
	Message4::d2 = d2;
}
void Message4::setD3(string d3) {
	Message4::d3 = d3;
}
void Message4::setD4(string d4) {
	Message4::d4 = d4;
}
#pragma endregion




