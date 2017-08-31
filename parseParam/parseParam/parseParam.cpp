// parseParam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPair(int& count)
{
	if(count == 2)
	{
		return true;
	}
	return false;
}


void parseParam(string &str, vector<string> resultStr, vector<char*>& segments)
{
	int len = (int)str.length();
	if(len <= 0)
	{
		resultStr.clear();
		return;
	}

	char* p = &str[0];
	char* phead = p;
	char* temp = "";
	bool flag = true;
	int count = 0;
	while(*p != '\0')
	{
		if(*p == '\"')
			count++;
		if((*p ==' ' && isPair(count)) || (*p == ' ' && count == 0))
		{
			if(isPair(count))//如果是引号内的
			{
				temp = (char*)malloc(sizeof(char) * (p - phead - 2));
				memcpy(temp, phead + 1, p - phead - 2);
				temp[p - phead - 2] = '\0';

				segments.push_back(temp);
				phead = p + 1;
			}
			else
			{
				temp = (char*)malloc(sizeof(char) * (p - phead));
				memcpy(temp, phead, p - phead);
				temp[p - phead] = '\0';

				segments.push_back(temp);
				phead = p + 1;
			}
			count = 0;
		}
		p++;
	}
	if(p != phead)
	{
		temp = (char*)malloc(sizeof(char) * (p - phead));
		memcpy(temp, phead, p - phead);
		temp[p - phead] = '\0';

		segments.push_back(temp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> resultStr;
	vector<char*> segments;

	string str = "";
	getline(cin, str);
	
	parseParam(str, resultStr, segments);
	
	for(int i = 0; i < (int)segments.size(); i++)
		cout<<segments[i]<<endl;

	system("pause");

	return 0;
}

