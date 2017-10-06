// ConsoleApplication36.cpp: 定义控制台应用程序的入口点。
//3.6.cpp掷骰子的随机游戏

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
using namespace std;

//掷骰子，计算和数，输出和数
int rolldice() {
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	int sum = die1 + die2;
	cout << "player rolled" << die1 << "+" << die2 << "=" << sum << endl;
	return sum;
}

//定义枚举类型表示比赛状态
enum gameresult { win, lose, playing };

int main()
{
	int sum, mypoint;
	gameresult status;

	unsigned seed;
	cout << "please enter an unsigned enteger:";
	cin >> seed;
	srand(seed);//传递种子
	sum = rolldice();
	switch (sum) {
	case 7:
	case 11:
		status = win;
		break;
	case 2:
	case 3:
	case 12:
		status = lose;
		break;
	default://其他情况
		status = playing;
		mypoint = sum;
		cout << "point is" << mypoint << endl;
		break;
	}
	while (status == playing) {
		sum = rolldice();
		if (sum == mypoint)
			status = win;
		else if (sum == 7)
			status = lose;
	}
	if (status == win)
		cout << "player wins" << endl;
	else
		cout << "player loses" << endl;
	return 0;
}

