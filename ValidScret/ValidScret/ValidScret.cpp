// ValidScret.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool haveSubstr(string &s)
{
	if(s.length() <= 2)
		return false;

	char* phead = &s[0];
	char* p = &s[0];
	char* q = &s[0];
	int cnt = 0;

	for(int i = 0; i < (int)s.length() - 1; i++)
	{	
		for(int j = i + 2; j < (int)s.length(); j++)
		{
			p = phead + i;
			q = phead + j;
			while(*p && *q)
			{
				if(*p == *q)
				{
					cnt++;
					q++;
					p++;

					if(cnt >= 2)
						return true;
				}
				else
					break; 
			}
		}
		cnt = 0;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int smallCaseCnt = 0;
	int bigCaseCnt = 0;
	int charCnt = 0;
	int numCnt = 0;
	int len = 0;
	bool have;
	vector<string> result;

	string str;

	while(cin>>str)
	{
		
		len = (int)str.length();

		char *p = &str[0];
		while(*p){
		if(*p >= '0' && *p <= '9')
			numCnt++;
		else if(*p >= 'a' && *p <= 'z')
			smallCaseCnt++;
		else if(*p >= 'A' && *p <= 'Z')
			bigCaseCnt++;
		else
			charCnt++;
		p++;
		}

		have = haveSubstr(str);

		if(((numCnt >= 1) && (smallCaseCnt >= 1) && (bigCaseCnt >= 1) 
			|| ((numCnt >= 1) && (smallCaseCnt >= 1) && (charCnt >= 1)) 
			|| ((numCnt >= 1) && (bigCaseCnt >= 1) && (charCnt >= 1))
			|| (smallCaseCnt >= 1) && (bigCaseCnt >= 1) && (charCnt >= 1))
			&& len >= 8 
			&& !have)
			result.push_back("OK");
		else
			result.push_back("NG");
	}

	for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter++)
		cout<<*iter<<endl;

	system("pause");

	return 0;
}

