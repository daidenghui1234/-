///****************************************************************************
/// @author  : 代登辉                                                         
/// @date    : 2021/5/31                                                                
/// @file    : wall.h                                                                  
/// @brief   : 墙模块                                                                
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************

#ifndef __WALL_H__
#define __WALL_H__
#include <iostream>
using namespace std;

class Wall
{
public:
	enum
	{
		ROW = 20,
		COL = 20	
	};
	/// <summary>
	/// 初始化墙壁
	/// </summary>
	void initWall();		// 初始化墙壁

	/// <summary>
	/// 画出墙壁
	/// </summary>
	void drawWall();		// 画出墙壁

	/// <summary>
	/// 修改地图对应坐标的值
	/// </summary>
	/// <param name="x">x轴</param>
	/// <param name="y">y轴</param>
	/// <param name="c">地图内容</param>
	void setWall(int x, int y, char c);		// 根据索引设置 二维数组中的内容
	
	/// <summary>
	/// 获取地图对应坐标的值
	/// </summary>
	/// <param name="x">x轴</param>
	/// <param name="y">y轴</param>
	/// <returns>地图内容</returns>
	char getWall(int x, int y);				// 根据索引获取当前位置的符号

private:
	char gameArray[ROW][COL];
}; // Wall



#endif // !__WALL_H__
