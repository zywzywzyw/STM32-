//#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define div(a) a = !a
#define setgravity(x,y) a=x,b=y

char sandbox[11][11] =
{
	2,2,2,2,2,2,2,2,2,2,2,
	2,0,0,0,0,0,0,0,0,2,2,
	2,0,0,0,0,0,0,0,2,0,2,
	2,0,0,0,0,0,0,2,0,0,2,
	2,0,0,0,0,0,2,0,0,0,2,
	2,0,0,0,0,2,0,0,0,0,2,
	2,0,0,0,2,0,0,0,0,0,2,
	2,0,0,2,0,0,0,0,0,0,2,
	2,0,2,0,0,0,0,0,0,0,2,
	2,2,0,0,0,0,0,0,0,0,2,
	2,2,2,2,2,2,2,2,2,2,2
};

_Bool flag,a,b,sand=1,bubble;
enum direction {up,down,left=0,right};
//enum object {bubble,sand};

void full_half(enum direction a);
void show_595();
void show_all();
void clear();
void shift(int x, int y,enum object d);
void invert();
void delay(unsigned long msec);

int main()
{
	srand((unsigned)time(NULL));
	setgravity(left, up);
	full_half(up);
	for (int i = 0; i < 1; i++)
	{
		system("CLS");
		div(sandbox[9][9]);
		shift(9, 9, bubble);
		div(sandbox[1][1]);
		shift(1,1,sand);
		show_all();
	}
	invert();
	//delay(50);
	for (int i = 0; i < 1; i++)
	{
		system("CLS");
		div(sandbox[9][9]);
		shift(9, 9, bubble);
		div(sandbox[1][1]);
		shift(1, 1, sand);
		show_all();
	}

}

void show_all() 
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			printf("%d ", sandbox[i][j]);
		printf("\n");
	}
	printf("\n");
}
void show_595()
{ 
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
			printf("%d ", sandbox[i][j]);
		printf("\n");
	}
}
void full_half(enum direction a)
{
	if (a==down)
	{
		for (int k = 8; k >-1; k--)
			for (int i = 1 + k, j = 1; sandbox[i][j] != 2; i--, j++)
				sandbox[i][j] = 1;
	}
	else if(a==up)
	{
		for (int k = 0; k < 8; k++)
			for (int i = 9, j = 9 - k; sandbox[i][j] != 2; i--, j++)
				sandbox[i][j] = 1;
	}
}

void clear()
{
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 10 - i; j++)
			sandbox[i][j] = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 9; j > 10 - i; j--)
			sandbox[i][j] = 0;
}

void shift(int x, int y,enum object d)
{
	(d) ? (div(a), div(b)) : (d = 0);
	char temp = sandbox[x][y];
	flag = rand() % 2;
	while (sandbox[x + 2*a-1][y] == !temp || sandbox[x][y + 2*b-1] == !temp)
	{
		sandbox[x][y] = !temp;
		if (sandbox[x + 2*a-1][y] == !temp && sandbox[x][y + 2*b-1] == !temp)
		{
			if (flag == 1) { sandbox[x][y + 2*b-1] = temp; y += 2*b-1; }
			else { sandbox[x + 2*a-1][y] = temp; x += 2*a-1; }
			flag = !flag;
		}
		else if (sandbox[x + 2*a-1][y] == !temp)
		{
			sandbox[x + 2*a-1][y] = temp; x += 2*a-1;
		}
		else if (sandbox[x][y + 2*b-1] == !temp)
		{
			sandbox[x][y + 2*b-1] = temp; y += 2*b-1;
		}
	}
	(d) ? (div(a), div(b)) : (d = 0);
}



void invert()
{
	_Bool temp = sandbox[1][1];
	for (int k = 0; k < 8; k++)
		for (int i = 1 + k, j = 1; sandbox[i][j] != 2; i--, j++)
			if (sandbox[i][j] == !temp) { shift(i,j,0);}
	temp = sandbox[9][9];
	for (int k = 0; k < 8; k++)
		for (int i = 9, j = 9 - k; sandbox[i][j] != 2; i--, j++)
			if (sandbox[i][j] == !temp) { shift(i, j, 1);  }
	show_all();
	div(a), div(b), div(sand), div(bubble);
}
	
void delay(unsigned long msec)
{
	clock_t now, start;

	start = clock();
	do
	{
		now = clock();
	} while (now - start < msec);
}