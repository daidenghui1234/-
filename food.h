#pragma once
#include <iostream>
#include "wall.h"
using namespace std;

class Food
{
public:
	/// <summary>
	/// ����Ĺ���
	/// </summary>
	/// <param name="tempWall">ǽ������</param>

	Food(Wall& tempWall);
	/// <summary>
	/// ����ʳ�� �������
	/// </summary>
	void setFood();

	/// <summary>
	/// x������
	/// </summary>
	int foodX;
	/// <summary>
	/// y������
	/// </summary>
	int foodY;
	/// <summary>
	/// ǽ������ �������������λ��
	/// </summary>
	Wall& wall;
};

