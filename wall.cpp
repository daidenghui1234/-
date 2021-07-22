///****************************************************************************
/// @author  : 代登辉                                                         
/// @date    : 2021/5/31                                                                
/// @file    : wall.cpp                                                                   
/// @brief   : 墙模块                                                                  
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************

#include "wall.h"

/// <summary>
/// 初始化墙壁
/// </summary>
void Wall::initWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			// 放墙壁
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
} // Wall::initWall()

/// <summary>
/// 画出墙壁
/// </summary>
void Wall::drawWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameArray[i][j] << " ";
		}
		switch (i)
		{
		case 5: {
			cout << "create by DaiDenghui";
			break;
		}
		case 6: {
			cout << "a:left";
			break;
		}
		case 7: {
			cout << "d:right";
			break;
		}
		case 8: {
			cout << "w:up";
			break;
		}
		case 9: {
			cout << "s:down";
			break;
		}
		default:
			break;
		}
		
		cout << endl;
	}
} // Wall::drawWall()

/// <summary>
/// 修改地图对应坐标的值
/// </summary>
/// <param name="x">x轴</param>
/// <param name="y">y轴</param>
/// <param name="c">地图内容</param>
void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
} // Wall::setWall()

/// <summary>
/// 获取地图对应坐标的值
/// </summary>
/// <param name="x">x轴</param>
/// <param name="y">y轴</param>
/// <returns>地图内容</returns>
char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
} // Wall::getWall()
