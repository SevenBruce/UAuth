#include "user.h"

#pragma region User
User::User()
{
	User::idi = randomString(RANDOM_STRING_LENGTH);
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::bi = randomString(RANDOM_NUMBER_LENGTH);
}

RegUser User::generateReg()
{
	string hpwi = hashSha256(User::bi + User::pwi);
	RegUser regUser(User::idi, hpwi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::ai = backUser.getAi();
	User::b1 = backUser.getB1();
	User::b2 = backUser.getB2();
	User::b3 = xor (User::bi, hashSha256(User::idi + User::pwi));
	User::g = backUser.getG();
}

void User::setSidj(string sidj)
{
	User::sidj = sidj;
}

Message1 User::generateM1()
{
	string bi = xor (User::b3, hashSha256(User::idi + User::pwi));
	User::hpwi = hashSha256(bi + User::pwi);

	User::r1 = randomString(RANDOM_NUMBER_LENGTH);
	string c1 = xor (xor (User::b1, hashSha256(User::idi + User::hpwi + User::ai)), hashSha256(User::idi + User::sidj + User::r1));
	string c2 = xor (User::r1, xor (User::b2, User::hpwi));

	User::alpha = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	User::C3 = User::g;
	User::C3 *= User::alpha;

	string c4 = hashSha256(c1 + c2 + ecn2String(User::C3));
	string temStr = User::idi + User::sidj + c1 + c4;
	string c5 = AES_encryption(User::r1, temStr);

	Message1 message1(c2, User::C3, c5, User::ai);
	return message1;
}

void User::getM4(Message4 m4) {
	string aiNew = xor (m4.getC13(), hashSha256(User::sidj + User::r1 + User::ai));
	ECn c15 = m4.getC8();
	c15 *= User::alpha;
	Big key;
	c15.get(key);
	User::sku = hashSha256(ecn2String(User::C3) + ecn2String(m4.getC8()) + big2String(key));
	//cout << "Usssor::sku: "; coutHash(User::sku);

	string temC10 = hashSha256( User::sidj + User::idi + User::sku);
	if (temC10 != m4.getC10()) {
		cout << "m4.getC10() not equal at user side, exit(7)" << endl;
		system("pause");
	}
	
	string temC14 = hashSha256(User::idi + User::sidj + User::ai + aiNew + ecn2String(User::C3) + ecn2String(m4.getC8()) + m4.getC10() + m4.getC12());
	if (temC14 != m4.getC14()) {
		cout << "m4.getC14() not equal at user side, exit(7)" << endl;
		system("pause");
	}

	User::b1 = xor (xor (User::b1, hashSha256(User::idi + User::hpwi + User::ai)), hashSha256(User::idi + User::hpwi + aiNew));
	User::b2 = xor (xor (m4.getC12(), hashSha256(User::idi + User::r1)), User::hpwi);
	User::ai = aiNew;


}
#pragma endregion



