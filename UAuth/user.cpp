#include "user.h"

#pragma region User
User::User()
{
	User::idi = randomString(RANDOM_STRING_LENGTH);
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::ri = randomString(RANDOM_STRING_LENGTH);

	User::mpi = (hashSha256(User::ri + User::idi + User::pwi));
}

RegUser User::generateReg()
{
	RegUser regUser = RegUser();
	regUser.setIdi(User::idi);
	regUser.setMpi(User::mpi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::fi = backUser.getFi();
	User::ki = backUser.getKi();
	User::li = backUser.getLi();
	User::g = backUser.getG();
}

void User::setSidj(string sidj)
{
	User::sidj = sidj;
}

Message1 User::generateM1()
{
	User::di = xor (User::fi, User::mpi);
	User::ei = xor (User::li, User::mpi);

	User::k1 = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	User::A = User::g;
	User::A *= User::k1;

	User::timeStamp = time(NULL);
	string m2m2 = hashSha256(ecn2String(User::A) + User::idi + User::sidj + User::di + std::to_string(User::timeStamp));
	string m1m1 = xor ((User::idi + User::sidj + m2m2), ei);

	Message1 message1(User::A, User::ki, m1m1, User::timeStamp);
	return message1;
}

void User::getM4(Message4 m4) {
	string temStr = xor (m4.getM6(), User::ei);
	string einew = temStr.substr(0, HASH_MESSAGE_LENGH);
	string k3 = temStr.substr(HASH_MESSAGE_LENGH, RANDOM_STRING_LENGTH);
	string m7Tem = temStr.substr(HASH_MESSAGE_LENGH + RANDOM_STRING_LENGTH);

	ECn temKey = m4.getB();
	temKey *= User::k1;
	Big key;
	temKey.get(key);
	User::skij = hashSha256(big2String(key));
	//cout << "Usssor::skij: "; coutHash(User::skij);

	string m4m4 = hashSha256(ecn2String(User::A) + User::skij + ecn2String(m4.getB()));
	string m7m7 = hashSha256(einew + k3 + User::di + std::to_string(User::timeStamp) + m4m4);

	if (m7m7 != m7Tem) {
		cout << "m7 not equal, exit(7)" << endl;
		system("pause");
	}
	User::ki = k3;
	User::li = xor (einew, User::mpi);
}
#pragma endregion



