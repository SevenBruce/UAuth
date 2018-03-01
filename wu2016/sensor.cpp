#include "sensor.h"

#pragma region Sensor
Sensor::Sensor()
{
	Sensor::sidj = randomString(RANDOM_STRING_LENGTH);
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
	Sensor::cj = backSensor.getCj();
	Sensor::g = backSensor.getG();
}

void Sensor::sensorCheckIdentity(string sidj){
	if (sidj != Sensor::sidj) {
		cout << "identity not matched in the received message from gateway" << endl;
		system("pause");
	}	
}

Message3 Sensor::getM2(Message2 m2)
{
	Sensor::sensorCheckIdentity(m2.getSidj());
	string temD1 = hashSha256(m2.getMii()+ m2.getSidj() + Sensor::cj  + ecn2String(m2.getB2()) );
		if (m2.getD1() != temD1) {
			cout << "m2.getD1() at sensor side not equal." << endl;
			system("pause");
		}
//	timeDeal(m2.getT2(), "T2");
//
//	string m3m3 = hashSha256(ecn2String(m2.getA()) + Sensor::sidj + Sensor::cj + std::to_string(m2.getT2()));
//	if (m2.getMii() != m3m3) {
//		cout << "m2 not equal." << endl;
//		system("pause");
//	}
//
	Sensor::beta = rand(160, 2);
	//cout << "k2:" << k2 << endl;
	Sensor::C1 = Sensor::g;
	Sensor::C1 *= Sensor::beta;

	ECn temKey = m2.getB2();
	temKey *= Sensor::beta;
	Big key;
	temKey.get(key);
	Sensor::sks = hashSha256(ecn2String(m2.getB2()) + ecn2String(Sensor::C1) + big2String(key));
	//cout << "key: "; cout << big2String(key) << endl;;
	//cout << "Sensor::skij: "; coutHash(Sensor::sks);

	string c3 = hashSha256(m2.getMii() + Sensor::sidj + Sensor::sks);
	string c4 = hashSha256(Sensor::cj + m2.getMii() + Sensor::sidj);
	Message3 m3(Sensor::C1, c3, c4);
	return m3;
}

#pragma endregion
