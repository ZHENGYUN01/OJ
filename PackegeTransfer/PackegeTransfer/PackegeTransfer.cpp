// PackegeTransfer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXLEN 100

using namespace std;

int PktTrans(char* pInput, int iLen, char* pOutput)
{
	if(pInput == NULL || pOutput == NULL)
		return -1;

	if((int)strlen(pInput) != iLen)
		return -1;
	
	char* cur = pInput;
	char* phead = pInput;
	vector<char*> segments;

	while(*cur != '\0')
	{
		if(*cur == ' ')
		{
			char* temp = (char*)malloc(sizeof(char) * (cur - phead));
			memcpy(temp, phead, cur - phead);
			temp[cur - phead] = '\0';

			segments.push_back(temp);

			phead = (++cur);
		}
		++cur;
	}
	if(cur != phead)
	{
		char* temp = (char*)malloc(sizeof(char) * (cur - phead));
		memcpy(temp, phead, cur - phead);
		temp[cur - phead] = '\0';

		segments.push_back(temp);
	}

	vector<char*>::iterator it = segments.begin();

	for(it; it != segments.end();)
	{
		if(strcmp("7E", (*it)) == 0)
		{
			(*it) = "7D";
			++it;
			it = segments.insert(it, "5E");
			continue;
		}

		if(strcmp("7D", (*it)) == 0)
		{
			++it;
			it = segments.insert(it, "5D");
			continue;
		}
		
		++it;
	}
	char* StartAndEnd = "7E";

	segments.insert(segments.begin(), StartAndEnd);
	segments.push_back(StartAndEnd);

	int size = 3 * segments.size();

	cur = pOutput;
	for(it = segments.begin(); it != segments.end(); ++it)
	{
		memcpy(cur, *it, 2);
		*(cur + 2) = ' ';
		cur =  cur + 3;
		cout<<(*it);
	}

	cout<<endl;

	pOutput[size - 1] = '\0';

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//1D 2B 3C 4D 5E 7E 6F 7D 7E
	//7E 1D 2B 3C 4D 5E 7D 5E 6F 7D  5D 7D 5E 7E 
	char *pInput = "1D 2B 3C 4D 5E 7E 6F 7D 7E";
	char *pOutput = (char*)malloc(sizeof(char) * MAXLEN);

	int iLen = (int)strlen(pInput);

	int ret = PktTrans(pInput, iLen, pOutput);

	cout<<pOutput<<endl;

	free(pOutput);

	system("pause");

	return 0;
}

