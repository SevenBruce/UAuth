#include "sensor.h"

#pragma region Sensor
Sensor::Sensor(ECn g)
{
	Sensor::sidj = randomString(RANDOM_STRING_LENGTH);
	Sensor::g = g;
}
string Sensor::getSidj()
{
	return Sensor::sidj;
}

RegSensor Sensor::generateRegSensor()
{
	RegSensor regSensor(Sensor::sidj);
	return regSensor;
}

void Sensor::getBackSensor(BackSensor backSensor)
{
	Sensor::b4 = backSensor.getB4();
}

void Sensor::sensorCheckIdentity(string sidj){
	if (sidj != Sensor::sidj) {
		cout << "identity not matched in the received message from gateway" << endl;
		system("pause");
	}	
}

Message3 Sensor::getM2(Message2 m2)
{
	string temStr = AES_decryption(Sensor::b4, m2.getC7());
	string temIdi = temStr.substr(0, RANDOM_STRING_LENGTH);
	string temSidj = temStr.substr(RANDOM_STRING_LENGTH, RANDOM_STRING_LENGTH);
	Sensor::sensorCheckIdentity(temSidj);
	string c6 = temStr.substr(RANDOM_STRING_LENGTH*2);
	string temC6 = hashSha256(temIdi + temSidj + ecn2String(m2.getC3()));
		if (temC6 != c6) {
			cout << "c6 at sensor side not equal." << endl;
			system("pause");
		}

	Sensor::beta = rand(160, 2);
	//cout << "k2:" << k2 << endl;
	Sensor::C8 = Sensor::g;
	Sensor::C8 *= Sensor::beta;

	ECn temKey = m2.getC3();
	temKey *= Sensor::beta;
	Big key;
	temKey.get(key);
	Sensor::sks = hashSha256(ecn2String(m2.getC3()) + ecn2String(Sensor::C8) + big2String(key));
	//cout << "key: "; cout << big2String(key) << endl;;
	//cout << "Sensor::sks: "; coutHash(Sensor::sks);

	string c10 = hashSha256(Sensor::sidj + temIdi +Sensor::sks);
	string c11 = hashSha256(Sensor::b4 + ecn2String(Sensor::C8) + c10);
	Message3 m3(Sensor::C8, c10, c11);
	return m3;
}

#pragma endregion
