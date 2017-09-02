// ObjectManager.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class KEY{
public:
	unsigned int key1;
	unsigned int key2;
	unsigned int key3;
};

typedef int Object;

vector<KEY> g_Object;

bool inRange(unsigned int &key)
{
	if(key >= 0 && key < 65535)
		return true;
	return false;
}

/************************************************************************* 
功能：增加单个对象 
输入： 
key1  外部关键字 KEY1  
key2  外部关键字KEY2 
key3  外部关键字KEY3 
输出：无 
返回：  
      -1 :失败(对象已经存在或者其它异常) 
       0 :成功 
***************************************************************************/ 
int AddObject(unsigned int key1, unsigned int key2, unsigned int key3)
{
	if(!(inRange(key1)) || (!inRange(key2)) || !(inRange(key3)))
		return -1;

	KEY Key = {key1, key2, key3};
	vector<KEY>::iterator iter = g_Object.begin();

	for(; iter != g_Object.end(); ++iter)
	{
		if((*iter).key1 == key1 && (*iter).key2 == key2 && (*iter).key3 == key3)
			return -1;
	}

	if(iter == g_Object.end())
		g_Object.push_back(Key);
	
	return 0;
}
/******************************************************************************** 
功能：删除一个或多个对象 
输入： 
      key1 外部关键字 KEY1  
      key2 外部关键字 KEY2 
      key3 外部关键字 KEY3 
输出：无 
返回：无 
 
说明：用例保证参数取值为合法值和通配符0xFFFFFFFF, 通配符表示0~65535范围内的任意值;  
      举例:key1=1,key2=2,key3= 0xFFFFFFFF，表示删除key1=1,key2=2的所有对象; 
           key1,key2,key3取值全为0xFFFFFFFF时,表示删除所有对象。 
*********************************************************************************/ 
int IsObjectExist(unsigned int, unsigned int, unsigned int);

bool haveGenChar(unsigned int key1, unsigned int key2, unsigned int key3)
{
	if(key1 == 4294967295 || key2 == 4294967295 || key3 == 4294967295)
		return true;
	return false;
}

int DeleteObject(unsigned int key1, unsigned int key2, unsigned int key3)
{	
	if(g_Object.size() == 0)
		return -1;
	
	if(!IsObjectExist(key1, key2, key3) && !haveGenChar(key1, key2, key3))
		return -1;

	vector<KEY>::iterator iter = g_Object.begin();
	for(;iter != g_Object.end();)
	{
		if(((4294967295 == key1) || ((*iter).key1 == key1))  
			&& (((*iter).key2 == key2) || (4294967295 == key2)) 
			&& (((*iter).key3 == key3) || (4294967295 == key3)))
		{	
			iter = g_Object.erase(iter);
			continue;
		}
		else
			iter++;
	}
	
	return 0;
}
/******************************************************************************** 
功能：查询单个对象是否存在 
输入： 
      key1 外部关键字 KEY1  
      key2 外部关键字 KEY2 
      key3 外部关键字 KEY3 
输出：无 
返回： 
      0：不存在 
      1：存在 
**********************************************************************************/ 
int IsObjectExist(unsigned int key1, unsigned int key2, unsigned int key3)
{

	KEY Key = {key1, key2, key3};

	vector<KEY>::iterator iter = g_Object.begin();
	
	for(; iter != g_Object.end(); ++iter)
	{
		if((*iter).key1 == key1 && (*iter).key2 == key2 && (*iter).key3 == key3)
			return 1;
	}
	return 0;
}
/****************************************************************************************************** 
Description     清空所有对象 
Prototype       void Clear(); 
Input Param     无 
Output Param    无 
Return Value    无 
 
********************************************************************************************************/ 
void Clear(void)
{
	g_Object.clear();
}

ostream& operator<<(ostream& os, const KEY& Key)
{
	os<<Key.key1<<' '<<Key.key2<<' '<<Key.key3<<endl;
	return os;
}

int _tmain(int argc, _TCHAR* argv[])
{

	AddObject(1, 1, 1);
	AddObject(2, 2, 2);
	AddObject(3, 3, 3);
	AddObject(1, 1, 1);
	AddObject(1, 2, 3);
	AddObject(1, 3, 3);
	AddObject(1, 4, 3);

	AddObject(3, 2, 1);

	cout<<IsObjectExist(1, 1, 1)<<endl;
	cout<<IsObjectExist(1, 2, 3)<<endl;
	
	DeleteObject(1,1,1);
	DeleteObject(1,1,1);
	DeleteObject(1, 0xFFFFFFFF, 3);

	cout<<IsObjectExist(1, 2, 3)<<endl;
	cout<<IsObjectExist(1, 3, 3)<<endl;
	cout<<IsObjectExist(1, 4, 1)<<endl;
	cout<<IsObjectExist(1, 1, 1)<<endl;
	cout<<IsObjectExist(4, 4, 4)<<endl;

	cout<<"****printing****"<<endl;
	int size = g_Object.size();
	for(int i = 0; i < size; i++)
	{
		cout<<g_Object[i]<<endl;
	}

	DeleteObject(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF);
	
	cout<<"****printing****"<<endl;
	size = g_Object.size();

	for(int i = 0; i < size; i++)
	{
		cout<<g_Object[i]<<endl;
	}

	system("pause");

	return 0;
}

