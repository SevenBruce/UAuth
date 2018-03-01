#include "user.h"


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
	User::g = backUser.getG();
	User::gatewayPublicKey = backUser.getGatePublicKey();
}

void User::setSidj(string sidj)
{
	User::sidj = sidj;
}

Message1 User::generateM1()
{
	User::di = xor (User::fi, User::mpi);

	User::k1 = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	User::A = User::g;
	User::A *= User::k1;

	ECn temKey = User::gatewayPublicKey;
	temKey *= User::k1;
	Big key;
	temKey.get(key);
	string kug = hashSha256(big2String(key));

	User::timeStamp = time(NULL);
	string m1m1 = xor ((User::idi + User::sidj), kug);
	//cout << "idi ::" << idi<<endl;
	//cout << "sidj::" << sidj << endl;
	User::m2m2 = hashSha256(ecn2String(User::A) + m1m1 + User::di + std::to_string(User::timeStamp));
	
	Message1 message1(User::A, m1m1, User::m2m2, User::timeStamp);
	return message1;
}

void User::getM4(Message4 m4) {

	string temM5 =  hashSha256(ecn2String(m4.getB()) + User::di + User::m2m2 + ecn2String(User::A) + to_string(User::timeStamp));
	if (temM5 != m4.getM5()) {
		cout << "m5 from gateway at user side not equal" << endl;
		system("pause");
	}

	ECn temKey = m4.getB();
	temKey *= User::k1;
	Big key;
	temKey.get(key);
	User::skij = hashSha256(big2String(key));

	//cout << "Userrr::skij: "; coutHash(User::skij);
}





