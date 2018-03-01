#include "user.h"

#pragma region User
User::User()
{
	User::idi = randomString(RANDOM_STRING_LENGTH);
	User::pwi = randomString(RANDOM_NUMBER_LENGTH);
	User::r0 = randomString(RANDOM_NUMBER_LENGTH);
}

RegUser User::generateReg()
{
	string mpi = hashSha256(User::r0 + User::pwi);
	string mii = hashSha256(User::r0 + User::idi);
	RegUser regUser(User::idi, mpi, mii);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::fi = backUser.getFi();
	User::ei = backUser.getEi();
	User::g = backUser.getG();
	User::di = xor (User::r0, hashSha256(User::idi + User::pwi));
}

void User::setSidj(string sidj)
{
	User::sidj = sidj;
}

Message1 User::generateM1()
{

	string r1 = xor (User::di, hashSha256(User::idi + User::pwi));
	User::mii = hashSha256(r1 + User::idi);
	User::mpi = hashSha256(r1 + User::pwi);

	User::r2 = randomString(RANDOM_NUMBER_LENGTH);
	User::r3 = randomString(RANDOM_NUMBER_LENGTH);
	User::miiNew = hashSha256(User::r2 + User::idi);

	string B1 = xor (User::r3, xor (User::ei, User::mpi));
	User::alpha = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	User::B2 = User::g;
	User::B2 *= User::alpha;

	string B3 = xor (xor (xor (User::fi, User::mii), User::miiNew), hashSha256(User::r3 + User::mii));

	string B4 = xor (User::idi, hashSha256(User::r3 + User::miiNew + ecn2String(User::B2)));
	string B5 = hashSha256(User::idi + User::mii + User::miiNew + User::sidj);
	//       Message1(string mii, string sidj, string b1, ECn b2, string b3, string b4, string b5);
	Message1 message1(User::mii, User::sidj, B1, User::B2, B3, B4, B5);
	return message1;
}

void User::getM4(Message4 m4) {
	string temD4 = hashSha256(User::idi + User::mii + User::miiNew + User::sidj + m4.getD2() + m4.getD3() + User::r3);

	if (temD4 != m4.getD4()) {
		cout << "m4.getD4() not equal at user side, exit(7)" << endl;
		system("pause");
	}

	ECn temKey = m4.getC1();
	temKey *= User::alpha;
	Big key;
	temKey.get(key);
	User::sku = hashSha256(ecn2String(User::B2) + ecn2String(m4.getC1()) + big2String(key));
	//cout << "Usssor::skij: "; coutHash(User::sku);

	string temC4 = hashSha256(User::mii + User::sidj + User::sku);

	if (temC4 != m4.getC3()) {
		cout << "m4.getC3() not equal at user side, exit(7)" << endl;
		system("pause");
	}

	User::di = xor (User::r2, hashSha256(User::idi + User::pwi));
	User::ei = xor (xor (m4.getD2(), hashSha256(User::miiNew + User::r3)), hashSha256(User::r2 + User::pwi));
	User::fi = xor (xor (m4.getD3(), User::miiNew), hashSha256(User::mii + User::r3));
}
#pragma endregion



