#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#define StatusSize 10



int gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}