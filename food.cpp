#include "food.h"
#include <Windows.h>
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy2(HANDLE hOut2, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut2, pos);
} //光标定位函数

/// <summary>
/// 事物的构造
/// </summary>
/// <param name="tempWall">墙的引用</param>
Food::Food(Wall& tempWall):wall(tempWall),foodX(0),foodY(0)
{
} // Food::Food

/// <summary>
/// 设置食物 随机产生
/// </summary>
void Food::setFood()
{
	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		if (wall.getWall(foodX, foodY) == ' ') {
			wall.setWall(foodX,foodY,'#');
			gotoxy2(hOut2, foodY * 2, foodX);
			cout << "#";
			break;
		} // if
	} // while
} // Food::setFood
