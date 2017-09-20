// buySystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


typedef struct card
{
	unsigned int credit;
	unsigned int balance;
}card;// 购物卡 

typedef struct cargo
{
	unsigned int kind;
	unsigned int charge;
	unsigned int num;
}cargo;// 货物

typedef struct order
{
	map<unsigned int, unsigned int> goods;// <商品的种类，数量>
}order;// 订单

typedef struct shopTrolley
{
	vector<order> totalOrders;;
	unsigned int totalBalance;
}shopTrolley;// 购物车


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

