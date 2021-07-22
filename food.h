#pragma once
#include <iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	/// <summary>
	/// 事物的构造
	/// </summary>
	/// <param name="tempWall">墙的引用</param>

	Food(Wall& tempWall);
	/// <summary>
	/// 设置食物 随机产生
	/// </summary>
	void setFood();

	/// <summary>
	/// x轴坐标
	/// </summary>
	int foodX;
	/// <summary>
	/// y轴坐标
	/// </summary>
	int foodY;
	/// <summary>
	/// 墙的引用 用来设置事物的位置
	/// </summary>
	Wall& wall;
};

