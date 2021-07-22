#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"
using namespace std;
#include <Windows.h>


class Snake
{
public:
	/// <summary>
	/// 蛇的有参构造
	/// </summary>
	/// <param name="tempWall">地图的引用</param>
	/// <param name="tempFood">食物的引用</param>
	Snake(Wall & tempWall,Food & tempFood);

	/// <summary>
	/// 上下左右 的枚举类型
	/// </summary>
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	/// <summary>
	/// 节点
	/// </summary>
	struct Point
	{
		int x;				// 数据域
		int y;
		Point* next;		// 指针域
	};  // 点

	/// <summary>
	/// 头节点
	/// </summary>
	Point* pHead;			// 头节点

	/// <summary>
	/// 墙（地图的引用）
	/// </summary>
	Wall& wall;

	/// <summary>
	/// 食物的引用
	/// </summary>
	Food& food;

	/// <summary>
	/// 循环标识
	/// </summary>
	bool isRool;	// 循环标识

	/// <summary>
	/// 初始化蛇
	/// </summary>
	void initSnake();		// 初始化蛇

	/// <summary>
	/// 销毁所有节点
	/// </summary>
	void destoryPoint();	// 销毁节点

	/// <summary>
	/// 添加节点
	/// </summary>
	/// <param name="x">x轴位置</param>
	/// <param name="y">y轴位置</param>
	void addPoint(int x, int y);	// 添加节点

	/// <summary>
	/// 删除尾巴
	/// </summary>
	void delPoint();	// 删除节点

	/// <summary>
	/// 移动蛇的位置
	/// </summary>
	/// <param name="key">键盘输入字符</param>
	/// <returns>是否移动成功（死亡）</returns>
	bool move(char key);	// 移动

	/// <summary>
	/// 时间
	/// </summary>
	/// <returns>时间</returns>
	int getSleepTime();

	/// <summary>
	/// 计算蛇的长度
	/// </summary>
	/// <returns>长度int</returns>
	int coutList();

	/// <summary>
	/// 获取分数
	/// </summary>
	/// <returns>分数</returns>
	int getScore();

};
