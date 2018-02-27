#ifndef UTILS_H
#define UTILS_H

#include <string>
#include<iostream>
using namespace std;

#include "big.h"
#include "mirdef.h"
#include "ecn.h"
#include <ctime>

void coutHash(string);

string randomString(int);

string ecn2String(ECn ecn);
string big2String(Big big);
string hashSha256(string org);
string xor (string org, string key);

bool isValidTime(int time);
void timeDeal(int time,string t1);
double diffclock(clock_t clock1, clock_t clock2);
#endif
