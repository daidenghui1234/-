#include "snake.h"

#include <Windows.h>

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量,并且这个只能在每个头文件中单独定义句柄和函数，否则无效
void gotoxy1(HANDLE hOut1, int x, int y)//其中x，y是与正常理解相反的，注意区分
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut1, pos);
} //光标定位函数

/// <summary>
/// 蛇的构造函数
/// </summary>
Snake::Snake(Wall& tempWall, Food& tempFood):wall(tempWall),food(tempFood),isRool(false)
{
	pHead = NULL;
} // Snake

/// <summary>
/// 初始化蛇
/// </summary>
void Snake::initSnake()
{
	destoryPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
} // Shake::initSnake

/// <summary>
/// 销毁所有节点
/// </summary>
void Snake::destoryPoint()
{
	Point* pCur = pHead;
	while (pCur!=NULL)	// 循环删除节点
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	} // while
} // Shake::destoryPoint

/// <summary>
/// 添加节点
/// </summary>
/// <param name="x">x轴</param>
/// <param name="y">y轴</param>
void Snake::addPoint(int x, int y)
{
	Point* newPonit = new Point;// 创建节点
	newPonit->x = x;
	newPonit->y = y;
	newPonit->next = NULL; 

	if (pHead != NULL) 
	{
		wall.setWall(pHead->x,pHead->y,'=');
		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}

	newPonit->next = pHead;	// 更新头
	pHead = newPonit;

	wall.setWall(pHead->x, pHead->y, '@');
	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "@";

} // Shake::addPoint

/// <summary>
/// 销毁节点
/// </summary>
void Snake::delPoint()
{
	// 两个节点才删除
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
	
	// 删除尾节点
	wall.setWall(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, (pCur->y)*2, pCur->x);
	cout << " ";
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
	 
}


/// <summary>
/// 移动蛇
/// </summary>
/// <param name="key">键盘输入</param>
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
	// 判断如果是尾巴不应该死亡
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	// 判断用户走的位置是否成功
	char cpoint = wall.getWall(x, y);

	if (pCur->x == x && pCur->y == y) {
		// 碰到尾巴的循环
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
			cout << "得分：" << getScore() << endl;
			cout << "Game Over" << endl;
			return false;
		}
	}

	
	// 移动成功分两种 迟到事物和未迟到事物
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
/// 获得暂停时间
/// </summary>
/// <returns>时间（难度）</returns>
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
/// 计算蛇的长度
/// </summary>
/// <returns>长度</returns>
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
