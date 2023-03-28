#define _CRT_SECURE_NO_WARNINGS 1//main函数在最下面
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
LQueue L;
Node N;
int arr[100],I=0;//用于记录数据类型
void mulu()
{
	printf("   ***************************************\n");
	printf("   *****1.初始化队列      6.入队 操作*****\n");
	printf("   *****2.销毁 队列       7.出队 操作*****\n");
	printf("   **        3.检查队列是否为空         **\n");
	printf("   *****4.查看队列头      8.清空 队列*****\n");
	printf("   *****5.查看队长度      9.遍历 函数*****\n");
	printf("   *****         10.操作函数        ******\n");
	printf("   *****         11.退出程序        ******\n");
	printf("   ***************************************\n");
}
void mulu1()
{
	printf("***************\n");
	printf("****1.整 型****\n");
	printf("****2.字符型***\n");
	printf("****3.浮点型***\n");
	printf("***************\n");
}
void initLQueue()//初始化队列
{
	int a;
	printf("请输入队列的节点数量：\n");
	scanf("%d", &a);
	getchar();
	system("cls");
	L.length = a;//存放长度
	Node* q = (Node*)malloc(sizeof(Node)),*o;//开辟一个新的空间
	L.rear = q;//存放尾部
	for (int i = 1; i <= a; i++)
	{
		printf("请选择节点%d的数据类型：\n", i);
		mulu1();//选择输入数据的类型
		int b;//用来记录数据类型
		int c;//以下是来记录不同类型的数据
		char cc;
		float ccc;
		scanf("%d", &b);
		getchar();
		printf("请输入节点%d数据：\n",i);
		switch (b)
		{
		case 1:
			arr[I++] = 1;//记录数据类型
			scanf("%d", &c);
			getchar();
			(q->data) = (int*)malloc(sizeof(int));//转换类型，储存数据
			*(int*)(q->data) = c;
			break;
		case 2:
			arr[I++] = 2;//记录数据类型
			scanf("%c", &cc);
			getchar();
			q->data = (char*)malloc(sizeof(char));
			*(char*)(q->data) = cc;
			break;
		case 3:
			arr[I++] = 3;//记录数据类型
			scanf("%f", &ccc);
			getchar();
			q->data = (float*)malloc(sizeof(float));
			*(float*)(q->data) = ccc;
			break;
		}
		if (i == a)
		{
			q->next = NULL;
			L.front = q;//存放头部
			break;
		}
		 o = (Node*)malloc(sizeof(Node));
		 q->next = o;
		 q = o;
		 printf("请按任意键继续....");
		 getchar();
		 system("cls");
	}
}
void destoryLQueue()
{
	Node* p, * q=NULL;
	p = L.rear;
	for (int i = 1; i <= L.length; i++)
	{
		if(i!=L.length)
		q = p->next;
		free(p);//释放每一个节点
		p = q;
	}
	L.rear = L.front = NULL;
	printf("销毁成功！！！\n");
}
int isEmptyLQueue()//检查队列是否为空
{
	if (L.front == NULL)
	{
		printf("队列为空！！！\n");
		return 1;
	}
	printf("队列不为空！！！\n");
	return 0;
}
void getHeadLQueue()//查看队头元素
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法查看\n");
		return;
	}
	Node* q=L.front;
	switch (arr[I-1])
	{
	case 1:
		printf("对头指针的数据：%d\n", *(int*)(q->data));
		break;
	case 2:
		printf("对头指针的数据：%c\n", *(char*)(q->data));
		break;
	case 3:
		printf("对头指针的数据：%f\n", *(float*)(q->data));
		break;
	}
}
void lengthLQueue()//队列长度
{
	if (isEmptyLQueue() == 1)
	{
		printf("不存在长度\n");
		return;
	}
	printf("队列长度为：%d\n", L.length);
}
void enLQueue()//入列操作
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法入列\n");
		return;
	}
	L.length++;//队列长度增加
	Node* q = (Node*)malloc(sizeof(Node));
	printf("请选择节点%d的数据类型：\n", L.length);
	mulu1();//选择输入数据的类型
	int b;//用来记录数据类型
	int c;//以下是来记录不同类型的数据
	char cc;
	float ccc;
	scanf("%d", &b);
	getchar();
	printf("请输入节点%d数据：\n", L.length);
	switch (b)
	{
	case 1:
		arr[I++] = 1;//记录数据类型
		scanf("%d", &c);
		getchar();
		(q->data) = (int*)malloc(sizeof(int));//转换类型，储存数据
		*(int*)(q->data) = c;
		break;
	case 2:
		arr[I++] = 2;//记录数据类型
		scanf("%c", &cc);
		getchar();
		q->data = (char*)malloc(sizeof(char));
		*(char*)(q->data) = cc;
		break;
	case 3:
		arr[I++] = 3;//记录数据类型
		scanf("%f", &ccc);
		getchar();
		q->data = (float*)malloc(sizeof(float));
		*(float*)(q->data) = ccc;
		break;
	}
	L.front->next = q;//改变头节点
	q->next = NULL;
	L.front = q;
	printf("插入成功！！！\n");
}
void deLQueue()//出队操作
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法出列\n");
		return;
	}
	Node* q = L.rear;
	for (int i = 1; i < L.length-1; i++)
	{
		q = q->next;//让q到达出列前的一个节点
	}
	q->next = NULL;
	free(L.front);
	L.front = q;
	L.length--;
	printf("出队成功！！！\n");
}
void clearLQueue()//清空队列
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法清空\n");
		return;
	}
	Node* q = L.rear;
	for (int i = 1; i <= L.length; i++)
	{
		free(q->data);
		if (i != L.length)
			q = q->next;
	}
	printf("清空成功！！！\n");
}
void lPrint()//操作函数
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法操作！！！\n");
		return;
	}
	printf("请输入想查询的节点：\n");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > L.length)
	{
		printf("请输入正确的序号：\n");
		return;
	}
	Node* q = L.rear;
	for (int i = 1; i < a; i++)
	{
		q = q->next;
	}
	switch (arr[a-1])
	{
	case 1:
		printf("节点%d的数据：%d\n",a, *(int*)(q->data));
		break;
	case 2:
		printf("节点%d的数据：%c\n",a, *(char*)(q->data));
		break;
	case 3:
		printf("节点%d的数据：%f\n", a,*(float*)(q->data));
		break;
	}
}
void traverseLQueue()//遍历函数
{
	if (isEmptyLQueue() == 1)
	{
		printf("无法遍历！！！\n");
		return;
	}
	printf("请输入遍历的起始节点：\n");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > L.length)
	{
		printf("请输入正确的序号：\n");
		return;
	}
	Node* q=L.rear;
	for (int i = 1; i < a; i++)
	{
		q = q->next;
	}
	for (int i = a; i <= L.length; i++)
	{
		switch (arr[i - 1])
		{
		case 1:
			printf("节点%d的数据：%d\n", i, *(int*)(q->data));
			break;
		case 2:
			printf("节点%d的数据：%c\n", i, *(char*)(q->data));
			break;
		case 3:
			printf("节点%d的数据：%f\n", i, *(float*)(q->data));
			break;
		}
		if(i!=L.length)
		q = q->next;
	}
}
int main()
{
	while (1)
	{
		mulu();
		int a;
		scanf("%d", &a);
		getchar();
		switch (a)
		{
		case 1:
			initLQueue();//初始化队列
			break;
		case 2:
			destoryLQueue();//销毁队列
			break;
		case 3:
			isEmptyLQueue();//检查队列是否为空
			break;
		case 4:
			getHeadLQueue();//查看队头元素
			break;
		case 5:
			lengthLQueue();//队列长度
			break;
		case 6:
			enLQueue();//入列操作
			break;
		case 7:
			deLQueue();//出队操作
			break;
		case 8:
			clearLQueue();//清空队列
			break;
		case 9:
			traverseLQueue();//遍历函数
			break;
		case 10:
			lPrint();//操作函数
			break;
		case 11:
			goto tiao;
		default:
			printf("请输入正确的序号");
		}
		printf("请按任意键继续....");
		getchar();
		system("cls");
	}
tiao:
	;
}