#include "gateway.h"


#pragma region Gateway
Gateway::Gateway(ECn g)
{
	Gateway::x = randomString(RANDOM_NUMBER_LENGTH);
	Gateway::idgwn = randomString(RANDOM_STRING_LENGTH);
	Gateway::g = g;
}

bool Gateway::isInIdentieis(string idenity) {
	vector<string>::iterator ret;

	ret = std::find(identities.begin(), identities.end(), idenity);
	if (ret == identities.end()) {
		return false;
	}
	return true;
}

BackUser Gateway::getRegUser(RegUser regUser)
{
	if (isInIdentieis(regUser.getIdi())) {
		cout << "this identity already exists" << endl;
		system("pause");
	}
	identities.push_back(regUser.getIdi());

	string ai = randomString(RANDOM_NUMBER_LENGTH);
	string b1 = xor (hashSha256(regUser.getIdi() + Gateway::idgwn + Gateway::x), hashSha256(regUser.getIdi() + regUser.getHpwi() + ai));
	string b2 = xor (hashSha256(Gateway::idgwn + Gateway::x + ai), regUser.getHpwi());

	BackUser backUser(ai, b1, b2, Gateway::g);
	return backUser;
}


BackSensor Gateway::getRegSensor(RegSensor regSensor)
{
	string b4 = hashSha256(regSensor.getSidj() + Gateway::idgwn + Gateway::x);
	//string b4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	BackSensor backSensor(b4, Gateway::g);
	return backSensor;
}


Message2 Gateway::getM1(Message1 m1)
{
	//authentication of the user
	Gateway::ai = m1.getAi();
	Gateway::r1 = xor (m1.getC2(), hashSha256(Gateway::idgwn + Gateway::x + Gateway::ai));
	string temStr = AES_decryption(Gateway::r1, m1.getC5());
	Gateway::idi = temStr.substr(0, RANDOM_STRING_LENGTH);
	Gateway::sidj = temStr.substr(RANDOM_STRING_LENGTH, RANDOM_STRING_LENGTH);
	string c1 = temStr.substr(RANDOM_STRING_LENGTH*2, HASH_MESSAGE_LENGH);
	string c4 = temStr.substr(RANDOM_STRING_LENGTH * 2+ HASH_MESSAGE_LENGH);
	string temC4 = hashSha256(c1+ m1.getC2() + ecn2String(m1.getC3()));
	if (temC4 != c4) {
		cout << "hash c4 from user at gateway side not equal" << endl;
		system("pause");
	}
	Gateway::C3 = m1.getC3();
	//generate the message for sensor
	Gateway::b4 = hashSha256(Gateway::sidj + Gateway::idgwn +Gateway::x);
	string c6 = hashSha256(Gateway::idi + Gateway::sidj + ecn2String(m1.getC3()));
	string c7 = AES_encryption(Gateway::b4 , (Gateway::idi + Gateway::sidj + c6));
	//Message2(string mii, string sidj, ECn B2, string d1)
	Message2 m2(m1.getC3(), c7);
	return m2;
}

Message4 Gateway::getM3(Message3 m3) {
	string temC11 = hashSha256(Gateway::b4 + ecn2String(m3.getC8()) + m3.getC10());
	if (temC11 != m3.getC11()) {
		cout << "m3.getC11() not equal at gateway side, exist(0)" << endl;
		system("pause");
	}

	string ainew = randomString(RANDOM_NUMBER_LENGTH);
	string c12 = xor (hashSha256(Gateway::idgwn + Gateway::x + ainew), hashSha256(Gateway::idi + Gateway::r1));
	string c13 = xor (ainew, hashSha256(Gateway::sidj + Gateway::r1 + Gateway::ai));
	string d14 = hashSha256(Gateway::idi + Gateway::sidj + Gateway::ai + ainew + ecn2String(Gateway::C3) + ecn2String(m3.getC8()) + m3.getC10() + c12);

	Message4 m4(m3.getC8(), m3.getC10(), c12, c13, d14);
	return m4;
}

void Gateway::clearIdentities() {
	identities.clear();
}
#pragma endregion
