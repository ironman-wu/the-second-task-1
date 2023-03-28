#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
char temp[100];
char shu[100], fu[100];//48~57 (40 )41 *42 +43 -45 /47
int t = 0;//用来记录输入的数据长度
int q = 0, w = 0;//q用来记录数组的，w用来记录符号的
void judgment()
{
	w--;
	if (fu[w] == ')')
	{
		fu[w--] = '\0';
		while (1)
		{
			if (fu[w] == '(')
			{
				fu[w--] = '\0';
				break;
			}
			shu[q++] = fu[w];
			fu[w--] = '\0';
		}
	}
	if (fu[w] == '+' || fu[w] == '-')
	{
		while (fu[w - 1] == '*' || fu[w - 1] == '/')
		{
			shu[q++] = fu[w - 1];
			fu[w - 1] = fu[w];
			fu[w--] = '\0';
		}
	}
	w++;
}
void bian()
{
	for (int i = 0; i < q; i++)
		if (shu[i] >= '0' && shu[i] <= '9')
			shu[i] -= 48;
}
void calculate()
{
	for (int i = 0; i < q; i++)
	{
		if (shu[i] == '+')
		{
			shu[i - 2] += shu[i - 1];
			for (int ii = i; ii < q; ii++)
			{
				shu[ii - 1] = shu[ii + 1];
			}
			i -= 2, q -= 2;
		}
		if (shu[i] == '-')
		{
			shu[i - 2] -= shu[i - 1];
			for (int ii = i; ii < q; ii++)
			{
				shu[ii - 1] = shu[ii + 1];
			}
			i -= 2, q -= 2;
		}
		if (shu[i] == '*')
		{
			shu[i - 2] *= shu[i - 1];
			for (int ii = i; ii < q; ii++)
			{
				shu[ii - 1] = shu[ii + 1];
			}
			i -= 2, q -= 2;
		}
		if (shu[i] == '/')
		{
			shu[i - 2] /= shu[i - 1];
			for (int ii = i; ii < q; ii++)
			{
				shu[ii - 1] = shu[ii + 1];
			}
			i -= 2, q -= 2;
		}
	}
	printf("%d\n", shu[0]);
}
int main()
{
	for (int i = 0; 1; i++)
	{
		scanf("%c", &temp[i]);
		t++;
		if (temp[i] == '\n')break;
	}
	//int r = 0;
	//for (int i = 0; i < t; i++)
	//{
	//	r++;
	//	if (temp[i] < '0' || temp[i]>'9')
	//	{
	//		int tem = 0, rr = r-1;
	//		for (int ii = 1; ii <= r-1; ii++)
	//		{
	//			tem = shu[i - rr] + tem;
	//			tem *= 10;
	//			rr--;
	//		}
	//		temp[i - r + 1] = tem;
	//		for (int ii = i; ii < q; ii++)
	//		{
	//			shu[i - r+1] = shu[i+1];
	//		}
	//	}
	//}
	for (int i = 0; i < t; i++)
	{
		if (temp[i] > '0' && temp[i] < '9')
		{
			shu[q++] = temp[i];
		}
		if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/'||temp[i]=='('||temp[i]==')')
		{
			fu[w++] = temp[i];
			judgment();
		}
		if (i == t - 2)
		{
			w--;
			for (; w >= 0;)
			{
				shu[q++] = fu[w];
				fu[w--] = '\0';
			}
		}
	}
	bian();
	calculate();
	printf("请按下任意键以结束程序.....");
	getchar();
}