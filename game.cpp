///****************************************************************************
/// @author  : 代登辉                                                         
/// @date    : 2021/5/31                                                                
/// @file    : game.cpp                                                                
/// @brief   : 贪吃蛇主文件                                                                
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************

#include <iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy(HANDLE hOut, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
} //光标定位函数

/// <summary>
/// 程序入口
/// </summary>
/// <returns></returns>
int main()
{
	srand((unsigned int)time(NULL));
	bool isDead = false;
	char preKey = NULL;
	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall); 
	food.setFood();

	Snake snake(wall,food);
	snake.initSnake();

	//wall.drawWall();
	gotoxy(hOut, 0, Wall::ROW);
	cout << "得分：" << snake.getScore() << endl;

	// 接受用户输入
	while (!isDead)
	{
		char key = _getch();
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// 判断本次的按键是否与上次冲突
				if (key == snake.UP && preKey == snake.DOWN ||
					key == snake.DOWN && preKey == snake.UP ||
					key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.RIGHT && preKey == snake.LEFT)
				{
					key = preKey;	// 强制将错误输入变为上一次移动的方向
				}
				else
				{
					preKey = key;	// 更新按键
				}
				
				if (snake.move(key) == true)
				{
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);
					cout << "得分：" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					break;
				}
			} // if
			else {
				key = preKey;	// 强制将错误输入变为上一次移动的方向
			}

		} while (!_kbhit());	// 当键盘没有输入时返回0
		
	}


	return 0;
} // main()
