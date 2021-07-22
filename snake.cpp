#include "snake.h"

#include <Windows.h>

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������,�������ֻ����ÿ��ͷ�ļ��е����������ͺ�����������Ч
void gotoxy1(HANDLE hOut1, int x, int y)//����x��y������������෴�ģ�ע������
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut1, pos);
} //��궨λ����

/// <summary>
/// �ߵĹ��캯��
/// </summary>
Snake::Snake(Wall& tempWall, Food& tempFood):wall(tempWall),food(tempFood),isRool(false)
{
	pHead = NULL;
} // Snake

/// <summary>
/// ��ʼ����
/// </summary>
void Snake::initSnake()
{
	destoryPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
} // Shake::initSnake

/// <summary>
/// �������нڵ�
/// </summary>
void Snake::destoryPoint()
{
	Point* pCur = pHead;
	while (pCur!=NULL)	// ѭ��ɾ���ڵ�
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	} // while
} // Shake::destoryPoint

/// <summary>
/// ��ӽڵ�
/// </summary>
/// <param name="x">x��</param>
/// <param name="y">y��</param>
void Snake::addPoint(int x, int y)
{
	Point* newPonit = new Point;// �����ڵ�
	newPonit->x = x;
	newPonit->y = y;
	newPonit->next = NULL; 

	if (pHead != NULL) 
	{
		wall.setWall(pHead->x,pHead->y,'=');
		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}

	newPonit->next = pHead;	// ����ͷ
	pHead = newPonit;

	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";

} // Shake::addPoint

/// <summary>
/// ���ٽڵ�
/// </summary>
void Snake::delPoint()
{
	// �����ڵ��ɾ��
	if (pHead == NULL||pHead->next ==NULL)
	{
		return;
	}
	Point* pCur = pHead->next;
	Point* pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	
	// ɾ��β�ڵ�
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, (pCur->y)*2, pCur->x);
	cout << " ";
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
	 
}


/// <summary>
/// �ƶ���
/// </summary>
/// <param name="key">��������</param>
/// <returns></returns>
bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;

	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}
	// �ж������β�Ͳ�Ӧ������
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	// �ж��û��ߵ�λ���Ƿ�ɹ�
	char cpoint = wall.getWall(x, y);

	if (pCur->x == x && pCur->y == y) {
		// ����β�͵�ѭ��
		isRool = true;
	}
	else
	{
		if (cpoint == '*' || cpoint == '=')
		{
			addPoint(x, y);
			if(cpoint != '=')
				delPoint();
			system("cls");
			wall.drawWall();
			cout << "�÷֣�" << getScore() << endl;
			cout << "Game Over" << endl;
			return false;
		}
	}

	
	// �ƶ��ɹ������� �ٵ������δ�ٵ�����
	if (cpoint == '#')
	{
		addPoint(x, y);
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();
		if (isRool == true) {
			wall.setWall(x, y, '@');
			/*gotoxy(hOut1, pHead->y * 2, pHead->x);
			cout << "@";*/
		}
	} // if
	return true;
}


/// <summary>
/// �����ͣʱ��
/// </summary>
/// <returns>ʱ�䣨�Ѷȣ�</returns>
int Snake::getSleepTime()
{
	int sleepTime = 0;
	int size = coutList();
	if (size < 5) {
		sleepTime = 300;
	}
	else if (size >= 5 && size <= 10) {
		sleepTime = 200;
	}
	else
	{
		sleepTime = 100;
	}
	return sleepTime;
}

/// <summary>
/// �����ߵĳ���
/// </summary>
/// <returns>����</returns>
int Snake::coutList()
{
	int size = 0;
	Point* curPoint = pHead;
	while (curPoint != NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}


int Snake::getScore()
{
	int size = coutList()-3;
	int score = size * 100;
	return score;
}
