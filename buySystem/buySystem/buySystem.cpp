// buySystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


typedef struct card
{
	unsigned int credit;
	unsigned int balance;
}card;// ���￨ 

typedef struct cargo
{
	unsigned int kind;
	unsigned int charge;
	unsigned int num;
}cargo;// ����

typedef struct order
{
	map<unsigned int, unsigned int> goods;// <��Ʒ�����࣬����>
}order;// ����

typedef struct shopTrolley
{
	vector<order> totalOrders;;
	unsigned int totalBalance;
}shopTrolley;// ���ﳵ


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

