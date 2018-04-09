#include "gateway.h"



Gateway::Gateway(ECn g)
{
	Gateway::privateKey = rand(160, 2);

	Gateway::g = g;
	Gateway::publicKey  = g;
	Gateway::publicKey *= Gateway::privateKey;
	Gateway::xgwn = randomString(RANDOM_STRING_LENGTH);
}

ECn Gateway::getG()
{
	return Gateway::g;
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

	string di = (hashSha256(regUser.getIdi() + Gateway::xgwn));
	string fi = xor (di, regUser.getMpi());
	
	BackUser backUser(fi, Gateway::g,Gateway::publicKey);
	return backUser;
}

string getIdPassword(string sidj) {
	return KEY_SENSOR_GATEWAY;
}

BackSensor Gateway::getRegSensor(RegSensor regSensor)
{
	string xgwn_sj = getIdPassword(regSensor.getSidj());
	timeDeal(regSensor.getT1(),"Sensor reg T1: ");
	string rj = xor (regSensor.getMnj(), xgwn_sj);
	string temMPj = hashSha256(xgwn_sj +rj+ regSensor.getSidj()+ to_string(regSensor.getT1()));

	//if (temMPj != regSensor.getMpj()) {
	//	cout << temMPj << endl;
	//	cout << regSensor.getMpj() << endl;
	//	cout << regSensor.getSidj() << endl;
	//	cout << rj << endl;
	//	cout << xgwn_sj << endl;
	//}

	string xj = (hashSha256(regSensor.getSidj() + Gateway::xgwn));
	string ej = xor (xj, hashSha256(regSensor.getSidj() + xgwn_sj));
	int t2 = time(NULL);
	string fj = hashSha256(xj + xgwn_sj + to_string(t2));
	BackSensor backSensor(ej,fj,Gateway::g,t2);
	return backSensor;
}


Message3 Gateway::getM2(Message2 m2)
{
	//authentication of the user
	timeDeal(m2.getMessage1().getT1(), "T1 from sensor");
	timeDeal(m2.getT2(),"T2 from sensor");

	ECn temKey = m2.getMessage1().getA();
	temKey *= Gateway::privateKey;
	Big key;
	temKey.get(key);
	string kug = hashSha256(big2String(key));
	
	string temStr = xor (m2.getMessage1().getM1(),kug);
	string idi = temStr.substr(0, RANDOM_STRING_LENGTH);
	string sidj = temStr.substr(RANDOM_STRING_LENGTH);

	string di = hashSha256(idi + Gateway::xgwn);
	string xj = hashSha256(sidj + Gateway::xgwn);

	string temM2 = hashSha256(ecn2String(m2.getMessage1().getA()) + m2.getMessage1().getM1() + di + to_string(m2.getMessage1().getT1()));
	if (temM2 != m2.getMessage1().getM2()) {
		cout<<"m2 from user not equal at gateway side"<<endl;
		system("pause");
	}

	string temM3 = hashSha256(ecn2String(m2.getB()) + m2.getMessage1().getM2() + xj + to_string(m2.getT2()));
	if (temM3 != m2.getM3()) {
		cout << "m3 from sensor not equal at gateway side" << endl;
		system("pause");
	}

	string m4m4 = hashSha256(ecn2String(m2.getMessage1().getA()) + xj + temM3 + ecn2String(m2.getB()) + to_string(m2.getT2()));
	string m5m5 = hashSha256(ecn2String(m2.getB()) + di + temM2 + ecn2String(m2.getMessage1().getA()) + to_string(m2.getMessage1().getT1()));

	return Message3(m4m4,m5m5);
	//Gateway::ei = hashSha256(m1.getKi() + Gateway::xgwn);
	//string temStr = xor (m1.getM1(), ei);

	//Gateway::idi = temStr.substr(0, RANDOM_STRING_LENGTH);
	//Gateway::di = hashSha256(Gateway::idi + Gateway::xgwn);
	//Gateway::sidj = temStr.substr(RANDOM_STRING_LENGTH, RANDOM_STRING_LENGTH);
	//Gateway::xj = hashSha256(Gateway::sidj + Gateway::xgwn);

	//string m2m2 = temStr.substr(RANDOM_STRING_LENGTH * 2);

	////check if m2' equals to hash
	//string tem = hashSha256(ecn2String(m1.getA()) +
	//	Gateway::idi +
	//	Gateway::sidj +
	//	Gateway::di +
	//	std::to_string(m1.getT1())
	//);
	//if (tem != m2m2) {
	//	cout << "hash M2 test not pass, exit(2)" << endl;
	//	system("pause");
	//}

	//// the generation of Message 2
	//Gateway::timeStamp1 = m1.getT1();
	//Gateway::A = m1.getA();

	//Gateway::timeStamp2 = time(NULL);
	//Gateway::m3 = hashSha256(ecn2String(Gateway::A) + Gateway::sidj + Gateway::xj + std::to_string(Gateway::timeStamp2));

	//Message2 m2(Gateway::A, Gateway::m3, Gateway::timeStamp2);
	//return m2;
}

void Gateway::clearIdentities() {
	identities.clear();
}

//Message4 Gateway::getM3(Message3 m3) {
//	string m5m5 = hashSha256(
//		ecn2String(Gateway::A) + Gateway::xj + Gateway::m3 + m3.getM4() + ecn2String(m3.getB()));
//	if (m5m5 != m3.getM5()) {
//		cout << "m5 not equal, exist(0)" << endl;
//		system("pause");
//	}
//
//	string k3 = randomString(RANDOM_STRING_LENGTH);
//	string einew = hashSha256(k3 + Gateway::xgwn);
//	string m7m7 = hashSha256(einew + k3 + Gateway::di + std::to_string(Gateway::timeStamp1) + m3.getM4());
//	string m6m6 = xor ((einew + k3 + m7m7), Gateway::ei);
//
//	Message4 m4(m3.getB(), m6m6);
//	return m4;
//}