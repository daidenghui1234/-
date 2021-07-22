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
	/// �ߵ��вι���
	/// </summary>
	/// <param name="tempWall">��ͼ������</param>
	/// <param name="tempFood">ʳ�������</param>
	Snake(Wall & tempWall,Food & tempFood);

	/// <summary>
	/// �������� ��ö������
	/// </summary>
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	/// <summary>
	/// �ڵ�
	/// </summary>
	struct Point
	{
		int x;				// ������
		int y;
		Point* next;		// ָ����
	};  // ��

	/// <summary>
	/// ͷ�ڵ�
	/// </summary>
	Point* pHead;			// ͷ�ڵ�

	/// <summary>
	/// ǽ����ͼ�����ã�
	/// </summary>
	Wall& wall;

	/// <summary>
	/// ʳ�������
	/// </summary>
	Food& food;

	/// <summary>
	/// ѭ����ʶ
	/// </summary>
	bool isRool;	// ѭ����ʶ

	/// <summary>
	/// ��ʼ����
	/// </summary>
	void initSnake();		// ��ʼ����

	/// <summary>
	/// �������нڵ�
	/// </summary>
	void destoryPoint();	// ���ٽڵ�

	/// <summary>
	/// ��ӽڵ�
	/// </summary>
	/// <param name="x">x��λ��</param>
	/// <param name="y">y��λ��</param>
	void addPoint(int x, int y);	// ��ӽڵ�

	/// <summary>
	/// ɾ��β��
	/// </summary>
	void delPoint();	// ɾ���ڵ�

	/// <summary>
	/// �ƶ��ߵ�λ��
	/// </summary>
	/// <param name="key">���������ַ�</param>
	/// <returns>�Ƿ��ƶ��ɹ���������</returns>
	bool move(char key);	// �ƶ�

	/// <summary>
	/// ʱ��
	/// </summary>
	/// <returns>ʱ��</returns>
	int getSleepTime();

	/// <summary>
	/// �����ߵĳ���
	/// </summary>
	/// <returns>����int</returns>
	int coutList();

	/// <summary>
	/// ��ȡ����
	/// </summary>
	/// <returns>����</returns>
	int getScore();

};
