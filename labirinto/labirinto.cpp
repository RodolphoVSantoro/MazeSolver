#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tx 12
#define ty tx
#define d (ty/2)
#define itr ty*ty

#define clear system("cls")

void delay(int seconds)
{
	clock_t inicio = clock();
	while (((clock() - inicio) / CLOCKS_PER_SEC)<seconds)
	{
	}
}

int menor(int v[],int n)
{
	int menor = v[0];
	for (int x = 1; x < n; x++)
	{
		if (v[x]<menor)
		{
			menor = v[x];
		}
	}
	return menor;
}

void exibe(int m[tx][ty])
{
	for (int i = 0; i < tx; i++)
	{
		for (int j = 0; j < ty; j++)
		{
			switch (m[i][j])
			{
			case 3:
				printf("R ");
				break;
			case 2:
				printf("o ");
				break;
			case 0:
				printf("  ");
				break;
			case 1:
				printf("H ");
				break;
			case 5:
				printf("X ");
				break;
			default:
				printf("  ");
				break;
			}
		}
		printf("\n");
	}
}

void exibev(int m[tx][ty])
{
	for (int i = 0; i < tx; i++)
	{
		for (int j = 0; j < ty; j++)
		{
			if (m[i][j] == 0)
			{
				printf("O ");
			}
			else
			{
				if (m[i][j] == 1)
				{
					printf("  ");
				}
				else
				{
					printf("%d ", ((m[i][j]) - 1));
				}
			}
		}
		printf("\n");
	}
}

int main()
{
	int px, py, fx, fy,rx,ry;
	//m1
	
	int m[tx][ty] = 
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 5, 1 },
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1 },
		{ 1, 2, 0, 0, 0, 2, 2, 0, 2, 0, 0, 1 },
		{ 1, 2, 2, 2, 0, 2, 2, 0, 2, 0, 0, 1 },
		{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 2, 0, 2, 0, 2, 2, 2, 2, 2, 2, 1 },
		{ 1, 2, 0, 2, 0, 2, 0, 0, 0, 0, 2, 1 },
		{ 1, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 1 },
		{ 1, 2, 0, 2, 0, 0, 0, 2, 2, 0, 2, 1 },
		{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	
	//m2
	/*
	int m[tx][ty] =
	{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 2, 2, 2, 5, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1 },
	{ 1, 2, 0, 0, 0, 2, 2, 0, 2, 0, 0, 1 },
	{ 1, 2, 2, 2, 0, 2, 2, 0, 2, 0, 0, 1 },
	{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 2, 0, 2, 0, 2, 2, 2, 2, 2, 2, 1 },
	{ 1, 2, 0, 2, 0, 2, 0, 0, 0, 0, 2, 1 },
	{ 1, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 1 },
	{ 1, 2, 0, 2, 0, 0, 0, 2, 2, 0, 2, 1 },
	{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	*/
	//m3
	/*
	int m[tx][ty] =
	{
		{ 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 1 },
		{ 1, 2, 2, 2, 0, 2, 0, 0, 0, 2, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 1 },
		{ 1, 0, 2, 2, 2, 2, 2, 2, 0, 2, 0, 1 },
		{ 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 2, 0, 0, 0, 2, 2, 2, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 2, 3, 2, 2, 2, 2, 2, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	*/
	//m4 
	/*
	int m[tx][ty] =
	{
		{ 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 2, 0, 2, 2, 2, 0, 1 },
		{ 1, 2, 2, 2, 0, 2, 0, 0, 0, 2, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 0, 1 },
		{ 1, 0, 2, 2, 2, 2, 2, 2, 0, 2, 0, 1 },
		{ 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 2, 0, 0, 0, 2, 2, 2, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 2, 3, 2, 2, 2, 2, 2, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	*/
	//m5
	/*
	int m[tx][ty] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 5, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 2, 0, 2, 2, 2, 0, 2, 2, 2, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1 },
		{ 1, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 1 },
		{ 1, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	*/
	int c[tx][ty];
	for (int x = 0; x < tx; x++)
	{
		for (int y = 0; y < ty; y++)
		{
			if (m[x][y] == 0 || m[x][y] == 5)
			{
				c[x][y] = 1;
				if (m[x][y] == 5)
				{
					fx = x;
					fy = y;
				}
			}
			else
			{
				c[x][y] = 0;
				if (m[x][y] == 3)
				{
					px = x;
					py = y;
					rx = x;
					ry = y;
				}
			}
		}
	}
	int v[4],n,passos=0;
	c[px][py]++;
	/*
	printf("Pressione enter para rodar cada iteracao\n");
	system("PAUSE");
	system("cls");
	*/
	exibe(m);
	delay(1);
	//system("PAUSE");
	clear;
	while (m[fx][fy] == 5)
	{
		n = 0;
		if (m[px - 1][py] == 5)
		{
			m[px - 1][py] = 3;
			m[px][py] = 0;
			c[px][py]++;
			px--;
			c[px][py]++;
			passos++;
			break;
		}
		if (m[px][py - 1] == 5)
		{
			m[px][py - 1] = 3;
			m[px][py] = 0;
			c[px][py]++;
			py--;
			c[px][py]++;
			passos++;
			break;
		}
		if (m[px + 1][py] == 5)
		{
			m[px + 1][py] = 3;
			m[px][py] = 0;
			c[px][py]++;
			px++;
			c[px][py]++;
			passos++;
			break;
		}
		if (m[px][py + 1] == 5)
		{
			m[px][py + 1] = 3;
			m[px][py] = 0;
			c[px][py]++;
			py++;
			c[px][py]++;
			passos++;
			break;
		}
		if (m[px - 1][py] == 0)
		{
			v[n] = c[px - 1][py];
			n++;
		}
		if (m[px][py - 1] == 0)
		{
			v[n] = c[px][py - 1];
			n++;
		}
		if (m[px + 1][py] == 0)
		{
			v[n] = c[px + 1][py];
			n++;
		}
		if (m[px][py + 1] == 0)
		{
			v[n] = c[px][py + 1];
			n++;
		}
		v[0] = menor(v, n);
		if (c[px - 1][py] == v[0])
		{
			m[px - 1][py] = 3;
			m[px][py] = 0;
			c[px][py]++;
			px--;
			passos++;
		}
		else
		{
			if (c[px][py - 1] == v[0])
			{
				m[px][py - 1] = 3;
				m[px][py] = 0;
				c[px][py]++;
				py--;
				passos++;
			}
			else
			{
				if (c[px + 1][py] == v[0])
				{
					m[px + 1][py] = 3;
					m[px][py] = 0;
					c[px][py]++;
					px++;
					passos++;
				}
				else
				{
					m[px][py + 1] = 3;
					m[px][py] = 0;
					c[px][py]++;
					py++;
					passos++;
				}
			}
		}
		exibe(m);
		//system("PAUSE");
		delay(1);
		clear;
	}
	exibe(m);
	//exibev(c);//(para demonstrar o array com a quantidade de vezes que o rato passou em cada parte do labirinto)
	printf("Completado com %d passos\n", passos);
	system("PAUSE");
	clear;
	return 0;
}