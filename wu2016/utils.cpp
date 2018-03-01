#include "utils.h"

string randomString(int len)
{
	string str = "";
	int i;
	for (i = 0; i<len; ++i)
		str += 'a' + rand() % 26;
	return str;
}

string ecn2String(ECn ecn)
{
	string result;

	ECn temEcn = ecn;
	char aString[100];
	Big temBigx, temBigy;

	temEcn.getxy(temBigx,temBigy);
	aString << temBigx;
	result += aString;

	aString << temBigy;
	result += aString;

	return result;
}

string big2String(Big big)
{
	string result;
	char aString[100];
	aString << big;
	result += aString;

	return result;
}

string hashSha256(string org)
{
	char hash[32];

	int i;
	sha256 sh;
	shs256_init(&sh);
	for (i = 0; org[i] != 0; i++) shs256_process(&sh, org[i]);
	shs256_hash(&sh, hash);
	
	string result;
	for (i = 0; i < 32; i++) {
		result += (unsigned char)hash[i];
	}
	return result;
}

void coutHash(string hash) {
	//int end = hash.length();
	int end = sizeof(hash);
	for (int i = 0; i<end; i++) printf("%02x", (unsigned char)hash[i]);
	printf("\n");
}


string xor (string org, string key)
{
	string encrypted = "";
	string tem = "";	

	while (tem.length()<org.length())
	{
		tem = tem.append(key);
	}

	for (int temp = 0, i = 0; temp < org.size(); temp++, i++) {
		encrypted += ((org[temp] - '0') ^ (tem[i] - '0')) + '0'; ;
	}
	return encrypted;
}

bool isValidTime(int timeCome) {
	int timeNow = time(NULL);
	if (timeNow < (timeCome + 10))
		return true;
	return false;
}

void timeDeal(int timeCome, string t1) {
	if (!isValidTime(timeCome)) {
		cout << "TimeStamp " + t1 +" not valid, exit." << endl;
		exit(0);
	}
}

double diffclock(clock_t clock1, clock_t clock2) {

	double diffticks = clock1 - clock2;
	double diffms = diffticks / (CLOCKS_PER_SEC / 1000);

	return diffms;
}


