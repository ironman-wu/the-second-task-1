#define _CRT_SECURE_NO_WARNINGS 1//main������������
#include<stdio.h>
#include<stdlib.h>
#include"LQueue.h"
LQueue L;
Node N;
int arr[100],I=0;//���ڼ�¼��������
void mulu()
{
	printf("   ***************************************\n");
	printf("   *****1.��ʼ������      6.��� ����*****\n");
	printf("   *****2.���� ����       7.���� ����*****\n");
	printf("   **        3.�������Ƿ�Ϊ��         **\n");
	printf("   *****4.�鿴����ͷ      8.��� ����*****\n");
	printf("   *****5.�鿴�ӳ���      9.���� ����*****\n");
	printf("   *****         10.��������        ******\n");
	printf("   *****         11.�˳�����        ******\n");
	printf("   ***************************************\n");
}
void mulu1()
{
	printf("***************\n");
	printf("****1.�� ��****\n");
	printf("****2.�ַ���***\n");
	printf("****3.������***\n");
	printf("***************\n");
}
void initLQueue()//��ʼ������
{
	int a;
	printf("��������еĽڵ�������\n");
	scanf("%d", &a);
	getchar();
	system("cls");
	L.length = a;//��ų���
	Node* q = (Node*)malloc(sizeof(Node)),*o;//����һ���µĿռ�
	L.rear = q;//���β��
	for (int i = 1; i <= a; i++)
	{
		printf("��ѡ��ڵ�%d���������ͣ�\n", i);
		mulu1();//ѡ���������ݵ�����
		int b;//������¼��������
		int c;//����������¼��ͬ���͵�����
		char cc;
		float ccc;
		scanf("%d", &b);
		getchar();
		printf("������ڵ�%d���ݣ�\n",i);
		switch (b)
		{
		case 1:
			arr[I++] = 1;//��¼��������
			scanf("%d", &c);
			getchar();
			(q->data) = (int*)malloc(sizeof(int));//ת�����ͣ���������
			*(int*)(q->data) = c;
			break;
		case 2:
			arr[I++] = 2;//��¼��������
			scanf("%c", &cc);
			getchar();
			q->data = (char*)malloc(sizeof(char));
			*(char*)(q->data) = cc;
			break;
		case 3:
			arr[I++] = 3;//��¼��������
			scanf("%f", &ccc);
			getchar();
			q->data = (float*)malloc(sizeof(float));
			*(float*)(q->data) = ccc;
			break;
		}
		if (i == a)
		{
			q->next = NULL;
			L.front = q;//���ͷ��
			break;
		}
		 o = (Node*)malloc(sizeof(Node));
		 q->next = o;
		 q = o;
		 printf("�밴���������....");
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
		free(p);//�ͷ�ÿһ���ڵ�
		p = q;
	}
	L.rear = L.front = NULL;
	printf("���ٳɹ�������\n");
}
int isEmptyLQueue()//�������Ƿ�Ϊ��
{
	if (L.front == NULL)
	{
		printf("����Ϊ�գ�����\n");
		return 1;
	}
	printf("���в�Ϊ�գ�����\n");
	return 0;
}
void getHeadLQueue()//�鿴��ͷԪ��
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷��鿴\n");
		return;
	}
	Node* q=L.front;
	switch (arr[I-1])
	{
	case 1:
		printf("��ͷָ������ݣ�%d\n", *(int*)(q->data));
		break;
	case 2:
		printf("��ͷָ������ݣ�%c\n", *(char*)(q->data));
		break;
	case 3:
		printf("��ͷָ������ݣ�%f\n", *(float*)(q->data));
		break;
	}
}
void lengthLQueue()//���г���
{
	if (isEmptyLQueue() == 1)
	{
		printf("�����ڳ���\n");
		return;
	}
	printf("���г���Ϊ��%d\n", L.length);
}
void enLQueue()//���в���
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷�����\n");
		return;
	}
	L.length++;//���г�������
	Node* q = (Node*)malloc(sizeof(Node));
	printf("��ѡ��ڵ�%d���������ͣ�\n", L.length);
	mulu1();//ѡ���������ݵ�����
	int b;//������¼��������
	int c;//����������¼��ͬ���͵�����
	char cc;
	float ccc;
	scanf("%d", &b);
	getchar();
	printf("������ڵ�%d���ݣ�\n", L.length);
	switch (b)
	{
	case 1:
		arr[I++] = 1;//��¼��������
		scanf("%d", &c);
		getchar();
		(q->data) = (int*)malloc(sizeof(int));//ת�����ͣ���������
		*(int*)(q->data) = c;
		break;
	case 2:
		arr[I++] = 2;//��¼��������
		scanf("%c", &cc);
		getchar();
		q->data = (char*)malloc(sizeof(char));
		*(char*)(q->data) = cc;
		break;
	case 3:
		arr[I++] = 3;//��¼��������
		scanf("%f", &ccc);
		getchar();
		q->data = (float*)malloc(sizeof(float));
		*(float*)(q->data) = ccc;
		break;
	}
	L.front->next = q;//�ı�ͷ�ڵ�
	q->next = NULL;
	L.front = q;
	printf("����ɹ�������\n");
}
void deLQueue()//���Ӳ���
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷�����\n");
		return;
	}
	Node* q = L.rear;
	for (int i = 1; i < L.length-1; i++)
	{
		q = q->next;//��q�������ǰ��һ���ڵ�
	}
	q->next = NULL;
	free(L.front);
	L.front = q;
	L.length--;
	printf("���ӳɹ�������\n");
}
void clearLQueue()//��ն���
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷����\n");
		return;
	}
	Node* q = L.rear;
	for (int i = 1; i <= L.length; i++)
	{
		free(q->data);
		if (i != L.length)
			q = q->next;
	}
	printf("��ճɹ�������\n");
}
void lPrint()//��������
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷�����������\n");
		return;
	}
	printf("���������ѯ�Ľڵ㣺\n");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > L.length)
	{
		printf("��������ȷ����ţ�\n");
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
		printf("�ڵ�%d�����ݣ�%d\n",a, *(int*)(q->data));
		break;
	case 2:
		printf("�ڵ�%d�����ݣ�%c\n",a, *(char*)(q->data));
		break;
	case 3:
		printf("�ڵ�%d�����ݣ�%f\n", a,*(float*)(q->data));
		break;
	}
}
void traverseLQueue()//��������
{
	if (isEmptyLQueue() == 1)
	{
		printf("�޷�����������\n");
		return;
	}
	printf("�������������ʼ�ڵ㣺\n");
	int a;
	scanf("%d", &a);
	getchar();
	if (a > L.length)
	{
		printf("��������ȷ����ţ�\n");
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
			printf("�ڵ�%d�����ݣ�%d\n", i, *(int*)(q->data));
			break;
		case 2:
			printf("�ڵ�%d�����ݣ�%c\n", i, *(char*)(q->data));
			break;
		case 3:
			printf("�ڵ�%d�����ݣ�%f\n", i, *(float*)(q->data));
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
			initLQueue();//��ʼ������
			break;
		case 2:
			destoryLQueue();//���ٶ���
			break;
		case 3:
			isEmptyLQueue();//�������Ƿ�Ϊ��
			break;
		case 4:
			getHeadLQueue();//�鿴��ͷԪ��
			break;
		case 5:
			lengthLQueue();//���г���
			break;
		case 6:
			enLQueue();//���в���
			break;
		case 7:
			deLQueue();//���Ӳ���
			break;
		case 8:
			clearLQueue();//��ն���
			break;
		case 9:
			traverseLQueue();//��������
			break;
		case 10:
			lPrint();//��������
			break;
		case 11:
			goto tiao;
		default:
			printf("��������ȷ�����");
		}
		printf("�밴���������....");
		getchar();
		system("cls");
	}
tiao:
	;
}