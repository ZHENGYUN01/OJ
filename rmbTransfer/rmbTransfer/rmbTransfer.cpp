// rmbTransfer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

string switchToBig(char& inChar)
{
	switch(inChar)
	{
	case '0':
		return "零";
	case '1':
		return "壹";
	case '2':
		return "贰";
	case '3':
		return "叁";
	case '4':
		return "肆";
	case '5':
		return "伍";
	case '6':
		return "陆";
	case '7':
		return "柒";
	case '8':
		return "捌";
	case '9':
		return "玖";
	default:
		return "";
	}
}
int zeroPosition(char* decimal)
{
	int pos1 = 0;
	int pos2 = 0;
	int pos3 = 0;

	if(decimal[0] == '0')
		pos1 = 1;
	if(decimal[1] == '0')
		pos2 = 2;
	if(pos1 && pos2)
		pos3 = 3;
	
	return (((pos1 > pos2) ? pos1 : pos2) > pos3)?(( pos1 > pos2) ? pos1: pos2):pos3;
}

string rmbTransfer(char* input)
{
	vector<char*> segments;//用来保存每4个数字组成的片段（*仟*佰*拾*）[亿万]

	char* cur = input;
	if(cur == NULL)
		return NULL;
	
	char* phead = input;
	char* decimal;
	while(*cur != '\0')
	{
		if(*cur == '.')
		{
			decimal = cur + 1;
			break;
		}
		cur++;
	}
	
	char* intNum = (char*)malloc(sizeof(char) * (cur - phead));
	memcpy(intNum, phead, cur - phead);
	intNum[cur - phead] = '\0';

	int count = (int)strlen(intNum);
	
	char* pre = --cur;

	for(int i = 0; i < count; i++)
	{
		if((i+1)%4 == 0 || i == (count - 1))
		{
			char* temp = (char*)malloc(sizeof(char) * 5);
			memcpy(temp, cur, pre - cur + 1);
			temp[pre - cur + 1] = '\0';

			segments.push_back(temp);
			pre = --cur;
			continue;
		}
		--cur;
	}

	char* Num[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
	char* Base[] = {"", "拾", "佰", "仟"};
	char* bigBase[] = {"万", "亿"};
	char* rmbBase[] = {"角", "分"};
	
	string ret = "人民币";
	
	vector<char*>::iterator iter = segments.end();
	count = segments.size();
	for(; count  > 0; count--)
	{
		int len = (int)strlen(segments[count - 1]);
		char* p = (segments[count - 1]);
		char *pre = p;
		for(int i = 0; i < len; i++)
		{
			if((*p == '0' && *pre != '0' && i != len - 1) || (*p == '0' && i == 0))
			{
				ret = ret + "零";
			}
			else if(*p != '0')
			{
				ret = ret + switchToBig(*p) + Base[len - 1 - i];
			}

			pre = p;
			p++;
		}
		if(count > 1)
			ret = ret + bigBase[count - 2];
	}
	ret = ret + "元";

	// decimal
	pre = decimal;
	count = (int)strlen(decimal);

	int pos = zeroPosition(decimal);
	if(pos == 3)//*.00的情况
	{
		ret = ret + "整";
		return ret;
	}

	for(int i = 0; i < count; i++)
	{
		if(*decimal == '0' && pos == 1)//*.01的情形
		{
			ret = ret + "零";
		}
		else if(*decimal != '0')//其他情况
		{
			ret = ret + switchToBig(*decimal) + rmbBase[i];
		}

		pre = decimal;
		decimal++;
	}
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* input = "112014.02";
	string result = rmbTransfer(input);
	cout<<result<<endl;

	char* input2 = "123410.10";
	string result2 = rmbTransfer(input2);
	cout<<result2<<endl;

	char* input3 = "100010.00";
	string result3 = rmbTransfer(input3);
	cout<<result3<<endl;

	system("pause");

	return 0;
}

