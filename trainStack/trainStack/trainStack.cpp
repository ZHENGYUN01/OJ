// trainStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int compare(vector<char> smallerSet)
{
	int size = (int)smallerSet.size();
	for(int i = 0; i < size; i++)
		for(int j = i + 1; j < size; j++)
		{
			if(smallerSet[i] > smallerSet[j])
			{
				continue;
			}
			else
				return 0;
		}
		return 1;
}

int trainStack(int maxTrain, char* outSquence)
{
	int size = (int)strlen(outSquence);
	if(size != maxTrain)
		return 0;
	if(maxTrain == 1)
		return 1;

	char *cur = outSquence;
	char *next = outSquence;
	vector<int> result;
	vector<char> smallerSet;
	int ret = 1;

	for(int i = 0 ;i < size; i++)
	{
		cur = (outSquence + i);

		for(int j = i + 1; j < size; j++)
		{
			next = outSquence + j;
			if(*cur > *next)
			{
				smallerSet.push_back(*next);
			}

		}
		int tempResult = compare(smallerSet);
		result.push_back(tempResult);

		smallerSet.clear();
	}
	for(vector<int>::iterator iter = result.begin(); iter !=result.end(); iter++)
	{
		if(*iter == 0)
			ret = 0;
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *outSquence = "31245";
	int maxTrain = 5;

	int ret = trainStack(maxTrain, outSquence);
	cout<<ret<<endl;

	system("pause");
	return 0;
}