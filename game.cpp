///****************************************************************************
/// @author  : ���ǻ�                                                         
/// @date    : 2021/5/31                                                                
/// @file    : game.cpp                                                                
/// @brief   : ̰�������ļ�                                                                
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

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy(HANDLE hOut, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut, pos);
} //��궨λ����

/// <summary>
/// �������
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
	cout << "�÷֣�" << snake.getScore() << endl;

	// �����û�����
	while (!isDead)
	{
		char key = _getch();
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}
		do {
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// �жϱ��εİ����Ƿ����ϴγ�ͻ
				if (key == snake.UP && preKey == snake.DOWN ||
					key == snake.DOWN && preKey == snake.UP ||
					key == snake.LEFT && preKey == snake.RIGHT ||
					key == snake.RIGHT && preKey == snake.LEFT)
				{
					key = preKey;	// ǿ�ƽ����������Ϊ��һ���ƶ��ķ���
				}
				else
				{
					preKey = key;	// ���°���
				}
				
				if (snake.move(key) == true)
				{
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);
					cout << "�÷֣�" << snake.getScore() << endl;
					Sleep(snake.getSleepTime());
				}
				else {
					isDead = true;
					break;
				}
			} // if
			else {
				key = preKey;	// ǿ�ƽ����������Ϊ��һ���ƶ��ķ���
			}

		} while (!_kbhit());	// ������û������ʱ����0
		
	}


	return 0;
} // main()
