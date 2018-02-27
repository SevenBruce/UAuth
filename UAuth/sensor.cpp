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
	Sensor::xj = backSensor.getXj();
	Sensor::g = backSensor.getG();
}

Message3 Sensor::getM2(Message2 m2)
{
	timeDeal(m2.getT2(), "T2");

	string m3m3 = hashSha256(ecn2String(m2.getA()) + Sensor::sidj + Sensor::xj + std::to_string(m2.getT2()));
	if (m2.getM3() != m3m3) {
		cout << "m2 not equal." << endl;
		system("pause");
	}

	Sensor::k2 = rand(160, 2);
	//cout << "k2:" << k2 << endl;
	Sensor::B = Sensor::g;
	Sensor::B *= Sensor::k2;

	ECn temKey = m2.getA();
	temKey *= Sensor::k2;
	Big key;
	temKey.get(key);
	Sensor::skij = hashSha256(big2String(key));
	//cout << "key: "; cout << big2String(key) << endl;;
	//cout << "Sensor::skij: "; coutHash(Sensor::skij);

	string m4m4 = hashSha256(ecn2String(m2.getA()) + Sensor::skij + ecn2String(Sensor::B));
	string m5m5 = hashSha256(Sensor::xj + m2.getM3() + m4m4 + ecn2String(Sensor::B));

	Message3 m3(Sensor::B, m4m4, m5m5);
	return m3;
}

#pragma endregion
