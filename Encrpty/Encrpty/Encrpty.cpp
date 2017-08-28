// Encrpty.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void Encrpty(string &str)
{
	int len = (int)str.length();
	if(len <= 0)
		return ;

	char* cur = &str[0];
	while(*cur)
	{
		if(*cur >= '0' && *cur <= '9')
			if(*cur == '9')
				*cur = '0';
			else
				*cur += 1;
		else if(*cur >= 'a' && *cur <= 'z')
			if(*cur == 'z')
				*cur = 'A';
			else
				*cur = 'A' + *cur - 'a' + 1;
		else if(*cur >= 'A' && *cur <= 'Z')
			if(*cur == 'Z')
				*cur = 'a';
			else
				*cur = 'a' + *cur - 'A' + 1;
		cur++;
	}
}

char* unEncrpty(string &str)
{
	int len = (int)str.length();
	if(len <= 0)
		return NULL;

	char* cur = &str[0];
	while(*cur)
	{
		if(*cur >= '0' && *cur <= '9')
			if(*cur == '0')
				*cur = '9';
			else
				*cur -= 1;
		else if(*cur >= 'a' && *cur <= 'z')
			if(*cur == 'a')
				*cur = 'Z';
			else
				*cur = 'A' + *cur - 'a' - 1;
		else if(*cur >= 'A' && *cur <= 'Z')
			if(*cur == 'A')
				*cur = 'z';
			else
				*cur = 'a' + *cur - 'A' - 1;
		cur++;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "Zabc1290z,.[]";
	Encrpty(s);

	cout<<s<<endl;

	string s2 = "aBCD2301A,.[]";
	unEncrpty(s2);

	cout<<s2<<endl;

	system("pause");

	return 0;
}

