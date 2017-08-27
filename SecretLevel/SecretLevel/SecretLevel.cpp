// SecretLevel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool isNum(char* ch)
{
	if(*ch >= '0' && *ch <= '9')
		return true;
	return false;
}

bool isBigAlphbet(char* ch)
{
	if(*ch >= 'A' && *ch <= 'Z')
		return true;
	return false;
}

bool isSmallAlphbet(char* ch)
{
	if(*ch >= 'a' && *ch <= 'z')
		return true;
	return false;
}


void lenScore(const int &len, int &score)
{
	if(len <= 4)
		score += 5;
	else if(len < 7)
		score += 10;
	else
		score += 25;
}

void alphbetScore( const int &BigAlphbetCnt, const int &SmallAlphbetCnt, int &score)
{
	if(BigAlphbetCnt > 0 && SmallAlphbetCnt > 0)
		score += 20;
	else if(BigAlphbetCnt == 0 && SmallAlphbetCnt == 0)
		score += 0;
	else
		score += 10;
}

void numScore(const int &NumCnt, int &score)
{
	if(NumCnt > 1)
		score += 20;
	else if(NumCnt == 1)
		score += 10;
}

void charScore(const int &CharCnt, int &score)
{
	if(CharCnt > 1)
		score += 20;
	else if(CharCnt == 1)
		score += 10;
}

void bonusScore(const int &NumCnt, const int &BigAlphbetCnt, const int &SmallAlphbetCnt, const int &CharCnt, int &score)
{
	if(BigAlphbetCnt > 0 && SmallAlphbetCnt > 0 && NumCnt > 0 && CharCnt > 0)
		score += 5;
	if(((BigAlphbetCnt == 0 && SmallAlphbetCnt > 0) || (BigAlphbetCnt > 0 && SmallAlphbetCnt == 0)) && NumCnt > 0 && CharCnt > 0)
		score += 3;
	if(((BigAlphbetCnt == 0 && SmallAlphbetCnt > 0) || (BigAlphbetCnt > 0 && SmallAlphbetCnt == 0)) && NumCnt > 0 && CharCnt == 0)
		score += 2;
}

int ComputeSecretScore(const int &len, const int &NumCnt, const int &BigAlphbetCnt, const int &SmallAlphbetCnt, const int &CharCnt)
{
	int score = 0;

	lenScore(len,score);
	
	alphbetScore(BigAlphbetCnt, SmallAlphbetCnt, score);

	numScore(NumCnt, score);

	charScore(CharCnt, score);

	bonusScore(NumCnt, BigAlphbetCnt, SmallAlphbetCnt, CharCnt, score);

	return score;
}

int checkSecretLevel(char *Secret)
{
	if(Secret == NULL)
		return 0;
	
	int Total = 0;
	int len = (int)strlen(Secret);
	int CharCnt = 0 ;
	int NumCnt = 0;
	int BigAlphbetCnt = 0;
	int SmallAlphbetCnt = 0;
	int length = len;
	char* cur = Secret;

	while(cur != '\0' && length--)
	{
		if(isNum(cur))
		{	
			NumCnt++;
		}
		else if(isBigAlphbet(cur))
		{
			BigAlphbetCnt++;
		}
		else if(isSmallAlphbet(cur))
		{
			SmallAlphbetCnt++;
		}
		else
			CharCnt++;
		cur++;
	}
	Total = ComputeSecretScore(len, NumCnt, BigAlphbetCnt, SmallAlphbetCnt, CharCnt);

	return Total;
}

void printSecretLevel(const int & score)
{
	char* result[] = {"VERY_WEAK", "WEAK", "AVERAGE", "STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE "};
	
	if(score >= 90)
		cout<<result[6]<<endl;
	else if(score >= 80)
		cout<<result[5]<<endl;
	else if(score >= 70)
		cout<<result[4]<<endl;
	else if(score >= 60)
		cout<<result[3]<<endl;
	else if(score >= 50)
		cout<<result[2]<<endl;
	else if(score >= 25)
		cout<<result[1]<<endl;
	else
		cout<<result[0]<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	char* secret = "38$@NoNoNo";
	int score = checkSecretLevel(secret);
	printSecretLevel(score);

	system("pause");

	return 0;
}

