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

void hashSha256(char org[],char test[])
{
	int i;
	sha256 sh;
	shs256_init(&sh);
	for (i = 0; test[i] != 0; i++) shs256_process(&sh, test[i]);
	shs256_hash(&sh, org);
	//for (i = 0; i<32; i++) printf("%02x", (unsigned char)org[i]);
	//printf("\n");
}
void hashSha256(string org, char * result)
{
	char hash[32];

	int i;
	sha256 sh;
	shs256_init(&sh);
	for (i = 0; org[i] != 0; i++) shs256_process(&sh, org[i]);
	shs256_hash(&sh, result);

	for (i = 0; i<32; i++) printf("%02x", (unsigned char)result[i]);
	printf("\n");
	
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
	int end = hash.length();
	for (int i = 0; i<end; i++) printf("%02x", (unsigned char)hash[i]);
	printf("\n");
}

void coutHash(char* hash) {
	int end = sizeof(hash);
	for (int i = 0; i<16; i++) printf("%02x", (unsigned char)hash[i]);
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


string  AES_encryption(string key1, string aString) {
	char key[32];
	for (int i = 0; i < 32; i++) key[i] = 0;
	key[0] = 1;
	aes a;
	char keyArray[32], iv[16];

	string result = "";
	//sha sh;
	//shs_init(&sh);
	//for (int i = 0; key[i] != 0; i++)shs_process(&sh, key[i]);
	//shs_hash(&sh, keyArray);

	for (int i = 0; i<16; i++) iv[i] = i;  // Set CFB IV
	aes_init(&a, MR_PCFB1, 32, keyArray, iv);// Set 128 bit AES Key
	int strEnd = aString.length();
	for (int i = 0; i<strEnd; i++) {
		char aChar = aString[i];
		aes_encrypt(&a, &aChar);
		result += aChar;
	}
	aes_end(&a);
	return result;
}

string AES_decryption(string key1, string aString) {

	aes a;
	char keyHash[32], iv[16];

	char key[32];
	for (int i = 0; i < 32; i++) key[i] = 0;
	key[0] = 1;
	string result = "";
	//sha sh;
	//shs_init(&sh);
	//for (int i = 0; key[i] != 0; i++)shs_process(&sh, key[i]);
	//shs_hash(&sh, keyHash);

	for (int i = 0; i<16; i++) iv[i] = i;  // Set CFB IV
	aes_init(&a, MR_PCFB1, 32, keyHash, iv);// Set 128 bit AES Key
	int strEnd = aString.length();
	for (int i = 0; i<strEnd; i++) {
		char aChar = aString[i];
		aes_decrypt(&a, &aChar);
		result += aChar;
	}
	aes_end(&a);
	return result;
}
