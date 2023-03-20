#include "sandbox.h"


typedef unsigned char u8;
typedef unsigned int u16;


#define div(a) a = !a
#define setgravity(x,y) a=x,b=y


unsigned char slide[] = {
	0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,
};

u8 all[]={
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
char sandbox[11][11] =
{
	2,2,2,2,2,2,2,2,2,2,2,
	2,2,0,0,0,0,0,0,0,0,2,
	2,0,2,0,0,0,0,0,0,0,2,
	2,0,0,2,0,0,0,0,0,0,2,
	2,0,0,0,2,0,0,0,0,0,2,
	2,0,0,0,0,2,0,0,0,0,2,
	2,0,0,0,0,0,2,0,0,0,2,
	2,0,0,0,0,0,0,2,0,0,2,
	2,0,0,0,0,0,0,0,2,0,2,
	2,0,0,0,0,0,0,0,0,2,2,
	2,2,2,2,2,2,2,2,2,2,2
};//0 sand              1 bubble
_Bool flag,a=1,b,sand=1,bubble;
enum direction {up,down,left=0,right};
int tick;


void show_all() 
{
  
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++);
			//printf("%d ", sandbox[i][j]);
		//printf("\n");
	}
	//printf("\n");
}

void show_sandboxru()
{ 
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
                {
                  send1((slide[i-1]<<(j-1))&(0x80),sandbox[i][j+1]);
                }
                show_74hc595();
	}
                  
        
}

void full_half(enum direction a)
{
	if (a==down)
	{
		for (int k = 0; k < 8; k++)
		for (int i = 9, j = 1+k; sandbox[i][j] != 2; i--, j--)
				sandbox[i][j] = 0;
	}
	else if(a==up)
	{
		for (int k = 0; k < 8; k++)
		for (int i = 9, j = 1+k; sandbox[i][j] != 2; i--, j--)
				sandbox[i][j] = 0;
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

void shift(int x, int y,_Bool d)
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
	_Bool temp = sandbox[9][1];
	for (int k = 0; k < 8; k++)
		for (int i = 9, j = 1+k; sandbox[i][j] != 2; i--, j--)
			if (sandbox[i][j] == !temp) { shift(i,j,!temp);}
	temp = sandbox[1][9];
	for (int k = 0; k < 8; k++)
		for (int i = 1+k, j = 9; sandbox[i][j] != 2; i--, j--)
			if (sandbox[i][j] == !temp) { shift(i, j, !temp);  }
	show_all();
	div(a), div(b), div(sand), div(bubble);
}

void send1(u8 datas,u8 data1)        
{
                HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,datas);//E1=DSS = (datas << a) & 0x80;GND 595_R
                HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,data1);//DS1 = (data1 << a) & 0x80;595_Lw
                HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0);//E2=SH_CP = 0;
                delay_us(1);
                HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);//SH_CP = 1;
}
void show_74hc595()                                        
{
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0);//E3=ST_CP = 0;
        delay_us(1);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);//ST_CP = 1;
}
void delay_us(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=10;  //自己定义
      while(i--) ;    
   }
}