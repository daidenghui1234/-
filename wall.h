///****************************************************************************
/// @author  : ���ǻ�                                                         
/// @date    : 2021/5/31                                                                
/// @file    : wall.h                                                                  
/// @brief   : ǽģ��                                                                
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
	/// ��ʼ��ǽ��
	/// </summary>
	void initWall();		// ��ʼ��ǽ��

	/// <summary>
	/// ����ǽ��
	/// </summary>
	void drawWall();		// ����ǽ��

	/// <summary>
	/// �޸ĵ�ͼ��Ӧ�����ֵ
	/// </summary>
	/// <param name="x">x��</param>
	/// <param name="y">y��</param>
	/// <param name="c">��ͼ����</param>
	void setWall(int x, int y, char c);		// ������������ ��ά�����е�����
	
	/// <summary>
	/// ��ȡ��ͼ��Ӧ�����ֵ
	/// </summary>
	/// <param name="x">x��</param>
	/// <param name="y">y��</param>
	/// <returns>��ͼ����</returns>
	char getWall(int x, int y);				// ����������ȡ��ǰλ�õķ���

private:
	char gameArray[ROW][COL];
}; // Wall



#endif // !__WALL_H__
