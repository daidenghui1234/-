///****************************************************************************
/// @author  : ���ǻ�                                                         
/// @date    : 2021/5/31                                                                
/// @file    : wall.cpp                                                                   
/// @brief   : ǽģ��                                                                  
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************

#include "wall.h"

/// <summary>
/// ��ʼ��ǽ��
/// </summary>
void Wall::initWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			// ��ǽ��
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
/// ����ǽ��
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
/// �޸ĵ�ͼ��Ӧ�����ֵ
/// </summary>
/// <param name="x">x��</param>
/// <param name="y">y��</param>
/// <param name="c">��ͼ����</param>
void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
} // Wall::setWall()

/// <summary>
/// ��ȡ��ͼ��Ӧ�����ֵ
/// </summary>
/// <param name="x">x��</param>
/// <param name="y">y��</param>
/// <returns>��ͼ����</returns>
char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
} // Wall::getWall()
