#include "gateway.h"


#pragma region Gateway
Gateway::Gateway(ECn g)
{
	Gateway::x = randomString(RANDOM_NUMBER_LENGTH);
	Gateway::idgwn = randomString(RANDOM_STRING_LENGTH);
	Gateway::g = g;
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
	string ei = xor (hashSha256(Gateway::idgwn + Gateway::x + regUser.getMii()), regUser.getMpi());
	string fi = xor (hashSha256(regUser.getMii() + Gateway::x), regUser.getMii());

	BackUser backUser(ei, fi, Gateway::g);
	return backUser;
}


BackSensor Gateway::getRegSensor(RegSensor regSensor)
{
	string cj = (hashSha256(regSensor.getSidj() + Gateway::x));
	BackSensor backSensor(cj, Gateway::g);
	return backSensor;
}


Message2 Gateway::getM1(Message1 m1)
{
	//authentication of the user
	Gateway::mii = m1.getMii();
	Gateway::r3 = xor (m1.getB1(), hashSha256(Gateway::idgwn + Gateway::x + Gateway::mii));
	Gateway::miiNew = xor (xor (m1.getB3(), hashSha256(Gateway::mii + Gateway::x)), hashSha256(Gateway::r3 + Gateway::mii));

	Gateway::idi = xor (m1.getB4(), hashSha256(Gateway::r3 + Gateway::miiNew + ecn2String(m1.getB2())));
	if (!isInIdentieis(Gateway::idi)) {
		//cout << "this user not registered" << endl;
		//cout << "user identity : " << endl;
		//cout << Gateway::idi << endl;
		//cout << "all identity : " << endl;
		for (std::vector<string>::iterator m = identities.begin(); m != identities.end(); m++)    //用迭代器的方式输出容器对象的值
		{
			cout << *m << endl;
		}
		system("pause");
	}
	Gateway::sidj = m1.getSidj();
	string temB5 = hashSha256(Gateway::idi + Gateway::mii + Gateway::miiNew + Gateway::sidj);
	if (temB5 != m1.getB5()) {
		cout << "hash getB5() from user at gateway side not equal" << endl;
		system("pause");
	}

	//generate the message for sensor
	Gateway::cj = hashSha256(Gateway::sidj + Gateway::x);
	string d1 = hashSha256(Gateway::mii + Gateway::sidj + Gateway::cj + ecn2String(m1.getB2()));
	//Message2(string mii, string sidj, ECn B2, string d1)
	Message2 m2(Gateway::mii, Gateway::sidj, m1.getB2(), d1);
	return m2;
}

Message4 Gateway::getM3(Message3 m3) {
	string temC4 = hashSha256(Gateway::cj + Gateway::mii + Gateway::sidj);
	if (temC4 != m3.getC4()) {
		cout << "m3.getC4() not equal at gateway side, exist(0)" << endl;
		system("pause");
	}

	string d2 = xor (hashSha256(Gateway::idgwn + Gateway::x + Gateway::miiNew), hashSha256(Gateway::miiNew + Gateway::r3));
	string d3 = xor (hashSha256(Gateway::miiNew + Gateway::x), hashSha256(Gateway::mii + Gateway::r3));
	string d4 = hashSha256(Gateway::idi + Gateway::mii + Gateway::miiNew + Gateway::sidj + d2 + d3 + Gateway::r3);

	Message4 m4(m3.getC1(), m3.getC3(), d2, d3, d4);
	return m4;
}
#pragma endregion
