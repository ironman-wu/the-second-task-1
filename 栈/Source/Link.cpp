#define _CRT_SECURE_NO_WARNINGS 1
#include "Linkhead.h"
#include <stdio.h>
#include<stdlib.h>
LinkStack linktop;
StackNode link;
//LinkStackPtr L;//用来记录栈链的链顶  这里看错题了，后来才发现，将就一下
int clearLLink();
int isEmptyLink();
void directory()
{
	printf("    **************************\n");
	printf("    *******1.初始化栈链*******\n");
	printf("    ****2.判断栈链是否为空****\n");
	printf("    ****3.获取栈链链头数据****\n");
	printf("    *******4.清理掉栈链*******\n");
	printf("    *******5.销毁掉栈链*******\n");
	printf("    *******6.检测栈的长度*****\n");
	printf("    *******7.入栈  8.出栈*****\n");
	printf("    *******9.结束程序*********\n");
	printf("    **************************\n");
}
void initLLink()//初始化栈链
{
	if (isEmptyLink() == 1)//判断当前是否存在栈链
	{
		printf("当前已存在链表，请继续输入链表数据：\n");
		LinkStackPtr p, q;
		p = q = linktop.top;
		for (int i = linktop.count; i >= 1; i--)
		{
			printf("请输入序号为%d的数据：\n", i);
			int a;
			scanf("%d", &a);
			getchar();
			p->data = a;
			if (i != 1)
				q = p->next;
			p = q;
		}
		return;
	}
	printf("请输入栈链的节点：\n");
	int a;
	scanf("%d", &a);
	getchar();
	linktop.count = a;
	LinkStackPtr p=NULL,q=NULL;
	for (int i = 1; i <= linktop.count; i++)
	{
		printf("第%d个节点的数据：\n", i);
		if (i == 1) {
			q  = (LinkStackPtr)malloc(sizeof(link));
			q->next = NULL;
		}
		int a;
		scanf("%d", &a);
		getchar();
		q->data = a;
		if (i == linktop.count)
		{
			linktop.top = q;
			break;
		}
		p = (LinkStackPtr)malloc(sizeof(link));//栈链的连接
		p->next = q;
		q = p;
	}
}
int isEmptyLink()//判断栈链是否为空
{
	if (linktop.top == NULL)
	{
		printf("栈链为空\n");
		return 0;
	}
	printf("栈链不为空\n");
	return 1;
}
void getTopLLink()//获得栈顶数据
{
	if (isEmptyLink() == 0)
	{
		printf("该栈链为空，栈顶无元素\n");
		return;
	}
	LinkStackPtr p;
	p = linktop.top;
	printf("栈顶的数据为%d：\n",p->data);
}
int clearLLink()//清空栈链
{
	if (isEmptyLink() == 0)
	{
		printf("当前不存在栈链\n");
		return 0;
	}
	LinkStackPtr p, q;
	p = q = linktop.top;
	int i;
	for ( i = 1; i <= linktop.count; i++)
	{
		if (i != linktop.count)//判断是否为最后一个节点
			p = q->next;
		q->data = 0;
		q = p;
	}
	printf("清理成功！！！\n");
	if (i == linktop.count+1)return 1;
}
void destroyLink()//销毁链表，释放内存
{
	if (isEmptyLink() == 0)
	{
		printf("不存在栈链\n");
		return;
	}
	LinkStackPtr p,q;
	p = q = linktop.top;
	for (int i = 1; i <= linktop.count; i++)
	{
		if (i != linktop.count)//判断是否为最后一个节点
		p = q->next;
		free(q);
		q = p;
	}
	linktop.top = NULL;
	printf("成功销毁！！！\n");
}
void LStackLink()//检测栈的长度
{
	printf("栈的长度为%d\n", linktop.count);
}
void pushLLink()//入栈
{
	if (isEmptyLink == 0)//判断栈链是否为空
	{
		printf("链栈为空，请先初始化栈链\n");
		return;
	}
	printf("请输入新的节点的数据：\n");
	int a;
	scanf("%d", &a);
	getchar();
	linktop.count++;//栈链的长度加一
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(link));
	p->next = linktop.top;
	p->data = a;
	linktop.top = p;//栈链的链头改变
	printf("入栈成功！！！\n");
}
void popLLink()//出栈
{
	if (isEmptyLink == 0)//判断栈链是否为空
	{
		printf("链栈为空，无法出栈\n");
		return;
	}
	LinkStackPtr p = linktop.top;
	if (linktop.count == 0)
	{
		printf("该栈中已不存在任何元素，无法出栈！！！\n");
		return;
	}
	linktop.top = linktop.top->next;
	free(p);
	linktop.count--;//栈链节点减一
	printf("出栈成功！！！\n");
}
int main()
{
	while (1)
	{
		directory();
		int a;
		scanf("%d", &a);
		getchar();
		switch (a)
		{
		case 1:
			initLLink();//初始化栈链
			break;
		case 2:
			isEmptyLink();//判断是否为空
			break;
		case 3:
			getTopLLink();//栈顶元素
			break;
		case 4:
			clearLLink();//清理栈链
			break;
		case 5:
			destroyLink();//销毁栈链
			break;
		case 6:
			LStackLink();//检测栈的长度
			break;
		case 7:
			pushLLink();//入栈
			break;
		case 8:
			popLLink();//出栈
			break;
		case 9:
			goto tiao;
		default:
			printf("输入的数据有误！！！");
		}
		printf("请按任意键继续....");
		getchar();
		system("cls");
	}
tiao:
	;
}