// buySystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <map>

using namespace std;

#define SUCCESS 1
#define FAIL 0

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

typedef struct Order
{
	map<unsigned int, unsigned int> goods;// <商品的种类，数量>
}Order;// 订单

typedef struct shopTrolley
{
	vector<Order> totalOrders;;
	unsigned int totalBalance;
}shopTrolley;// 购物车

typedef struct BUYER
{
	shopTrolley myTrolley;
	Order myOrder;
	card myCard;
}BUYER;// 一个购物者

BUYER buyer;

void initSystem()
{
	buyer.myCard.balance = 3000;
	buyer.myCard.credit = 150;

	buyer.myOrder.goods.clear();
	buyer.myTrolley.totalOrders.clear();
	buyer.myTrolley.totalBalance = 0;
}

void buyAction()
{


}

void deleteAction()
{


}

void queryCard()
{
	cout<<buyer.myCard.balance<<endl;
	cout<<buyer.myCard.credit<<endl;
}

void queryTrolley()
{
	unsigned int numOfOrder = buyer.myTrolley.totalOrders.size();
	vector<Order> totalOrders = buyer.myTrolley.totalOrders;

	vector<Order>::iterator iter = totalOrders.begin();
	for(; iter != totalOrders.end(); ++iter)
	{
		// 待完成
	}
}

void queryAction(const char &type)
{
	if(type == '0')
	{
		queryCard();
	}
	else
	{
		queryTrolley();
	}
}

void stopSystem()
{
    return SUCCESS;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

