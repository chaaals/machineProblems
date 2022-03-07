#include<stdio.h>
#include<conio.h>
#include<windows.h>

//functions
void gotoxy(short x, short y);    //gotoxy boilerplate

int main()
{	
	gotoxy(1,1);printf("Anunei");
	return 0;
}

void gotoxy(short x, short y)   //gotoxy boilerplate                                              
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
