#include "sensor.h"

Sensor::Sensor()
{
	Sensor::sidj = randomString(RANDOM_STRING_LENGTH);
	Sensor::xgwn_sj = KEY_SENSOR_GATEWAY;
}
string Sensor::getSidj()
{
	return Sensor::sidj;
}

RegSensor Sensor::generateRegSensor()
{
	string rj = randomString(RANDOM_NUMBER_LENGTH);
	string mnj = xor (rj, Sensor::xgwn_sj);
	int t1 = time(NULL);
	string mpj = hashSha256(Sensor::xgwn_sj + rj + Sensor::sidj + to_string(t1));
	RegSensor regSensor(Sensor::sidj,mnj,mpj,t1);
	return regSensor;
}

void Sensor::getBackSensor(BackSensor backSensor)
{
	string temKey = hashSha256(Sensor::sidj + Sensor::xgwn_sj);
	string temXj = xor(backSensor.getEj(),temKey);
	string temFj = hashSha256(temXj + Sensor::xgwn_sj + to_string(backSensor.getT2()));

	if (temFj == backSensor.getFj()) {
		Sensor::xj = temXj;
		Sensor:g = backSensor.getG();
	}
}

Message2 Sensor::getM1(Message1 m1)
{
	timeDeal(m1.getT1(), "T1 from user in login phase");
	Sensor::k2 = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	Sensor::B = Sensor::g;
	Sensor::B *= Sensor::k2;
	Sensor::A = m1.getA();
	Sensor::timeStamp2 = time(NULL);
	Sensor::m3m3 = hashSha256(ecn2String(Sensor::B) + m1.getM2() + Sensor::xj + to_string(Sensor::timeStamp2));
	
	Message2 m2(m1, Sensor::B, Sensor::m3m3, Sensor::timeStamp2);
	return m2;
}


Message4 Sensor::getM3(Message3 m3)
{
	string temM4 = hashSha256(ecn2String(Sensor::A) + xj + Sensor::m3m3 + ecn2String(Sensor::B) + to_string(Sensor::timeStamp2));
	if (temM4 != m3.getM4()) {
		cout<<"m4 from gateway at sensor side not equal"<<endl;
		system("pause");
	}
	ECn temKey = Sensor::A;
	temKey *= Sensor::k2;
	Big key;
	temKey.get(key);
	Sensor::skij = hashSha256(big2String(key));
	//cout << "Sensor::skij: "; coutHash(Sensor::skij);
	Message4 m4(Sensor::B, m3.getM5());
	return m4;
}