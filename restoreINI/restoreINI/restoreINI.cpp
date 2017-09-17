// restoreINI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <string>

using namespace std;
#define MAXLEN = 100
char* cmd[] = {"reset",
			   "reset board",
               "board add",
               "board delet",
               "reboot backplane",
               "backplane abort"};

char* excute[] = {"reset what",
                  "board fault",
				  "where to add",
				  "no bard at all",
				  "impossible",
				  "install first",
				  "unkown commadn"};

char* excuteAction(string & instr)
{
	if(instr.length() == 0)
		return excute[6];
	char* incommand = &instr[0];
	if(incommand == NULL)
		return NULL;
	bool match = false;
	for(int i = 0; i < 6; i++)
	{
		char* pCur = incommand;
		char* command = cmd[i];

		while(*pCur != '\0' && *command != '\0')
		{
			if(*pCur == ' ')
			{
				while(*command != '\0' && *command != ' ')
				{
					command++;				
				}
				if(*command == '\0')
					break;
			}
			if(*pCur == *command)
			{
				pCur++;
				command++;
				if(*pCur == '\0')
				{
					match = true;
				}
			}
			else
				break;
		}
		if(match)
			return excute[i];
	}
	return excute[6];
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* result;
	string incommand = "";

	while(getline(cin, incommand))
	{
		result = excuteAction(incommand);
		cout<<result<<endl;
	}
	system("pause");
	return 0;
}

