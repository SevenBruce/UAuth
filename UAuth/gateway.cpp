#include "gateway.h"


#pragma region Gateway
Gateway::Gateway(ECn g)
{
	Gateway::xgwn = randomString(RANDOM_NUMBER_LENGTH);
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
	//cout << isInIdentieis(regUser.getIdi()) << endl;
	//cout << regUser.getIdi() << endl;
	if (isInIdentieis(regUser.getIdi())) {
		cout << "this identity already exists" << endl;
		system("pause");
	}
	identities.push_back(regUser.getIdi());

	string fi = xor ( hashSha256(regUser.getIdi() + Gateway::xgwn) ,  regUser.getMpi() );
	string ki = randomString(RANDOM_NUMBER_LENGTH);
	string li = xor ( hashSha256(ki + Gateway::xgwn) , regUser.getMpi());

	BackUser backUser(fi, li, ki, Gateway::g);
	return backUser;
}


BackSensor Gateway::getRegSensor(RegSensor regSensor)
{
	string xj = hashSha256(regSensor.getSidj() + Gateway::xgwn);
	//string xj = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	BackSensor backSensor(xj, Gateway::g);
	return backSensor;
}


Message2 Gateway::getM1(Message1 m1)
{
	//authentication of the user
	timeDeal(m1.getT1(), "T1");

	Gateway::ei = hashSha256(m1.getKi() + Gateway::xgwn);
	string temStr = xor (m1.getM1(), ei);

	string idi = temStr.substr(0, RANDOM_STRING_LENGTH);
	Gateway::di = hashSha256(idi + Gateway::xgwn);
	string sidj = temStr.substr(RANDOM_STRING_LENGTH, RANDOM_STRING_LENGTH);
	Gateway::xj = hashSha256(sidj + Gateway::xgwn);

	string m2m2 = temStr.substr(RANDOM_STRING_LENGTH * 2);

	//check if m2' equals to hash
	string tem = hashSha256(ecn2String(m1.getA()) +
		idi +
		sidj +
		Gateway::di +
		std::to_string(m1.getT1())
	);
	if (tem != m2m2) {
		cout << "hash M2 test not pass, exit(2)" << endl;
		system("pause");
	}

	// the generation of Message 2
	Gateway::timeStamp1 = m1.getT1();

	Gateway::timeStamp2 = time(NULL);
	Gateway::m3 = hashSha256(ecn2String(m1.getA()) + sidj + Gateway::xj + std::to_string(Gateway::timeStamp2));

	Message2 m2(m1.getA(), Gateway::m3, Gateway::timeStamp2);
	return m2;
}

Message4 Gateway::getM3(Message3 m3) {
	string m5m5 = hashSha256(
		Gateway::xj + Gateway::m3 + m3.getM4() + ecn2String(m3.getB()));
	if (m5m5 != m3.getM5()) {
		cout << "m5 not equal, exist(0)" << endl;
		system("pause");
	}

	string k3 = randomString(RANDOM_NUMBER_LENGTH);
	string einew = hashSha256(k3 + Gateway::xgwn);
	string m7m7 = hashSha256(einew + k3 + Gateway::di + std::to_string(Gateway::timeStamp1) + m3.getM4());
	string m6m6 = xor ((einew + k3 + m7m7), Gateway::ei);

	Message4 m4(m3.getB(), m6m6);
	return m4;
}

void Gateway::clearIdentities() {
	identities.clear();
}
#pragma endregion
