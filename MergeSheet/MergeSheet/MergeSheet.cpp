// MergeSheet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <iostream>


using namespace std;

typedef struct record
{
	int index;
	int val;
}record;

map<int, int> g_map;

int _tmain(int argc, _TCHAR* argv[])
{
	int keyValNum = 0;
	cin>>keyValNum;
	
	int index;
	int val;
	record temprecord;
	vector<record> records;

	while(keyValNum--)
	{
		cin>>index>>val;
		temprecord.index = index;
		temprecord.val = val;

		records.push_back(temprecord);
	}

	for(vector<record>::iterator iter = records.begin(); iter != records.end(); iter++)
	{
		map<int, int>::iterator it = g_map.find(iter->index);
		if(it == g_map.end())
			g_map.insert(make_pair(iter->index, iter->val));
		else
		{	
			int temval = it->second;
			temval += iter->val;

			g_map.erase(it);
			g_map.insert(make_pair(iter->index, temval));
		}
	}

	for(map<int, int>::iterator iter = g_map.begin(); iter != g_map.end(); iter++)
	{
		cout<<iter->first<<' '<<iter->second<<endl;
	}

	system("pause");

	return 0;
}

