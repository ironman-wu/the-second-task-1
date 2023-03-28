#define _CRT_SECURE_NO_WARNINGS 1
#include "Linkhead.h"
#include <stdio.h>
#include<stdlib.h>
LinkStack linktop;
StackNode link;
//LinkStackPtr L;//������¼ջ��������  ���￴�����ˣ������ŷ��֣�����һ��
int clearLLink();
int isEmptyLink();
void directory()
{
	printf("    **************************\n");
	printf("    *******1.��ʼ��ջ��*******\n");
	printf("    ****2.�ж�ջ���Ƿ�Ϊ��****\n");
	printf("    ****3.��ȡջ����ͷ����****\n");
	printf("    *******4.�����ջ��*******\n");
	printf("    *******5.���ٵ�ջ��*******\n");
	printf("    *******6.���ջ�ĳ���*****\n");
	printf("    *******7.��ջ  8.��ջ*****\n");
	printf("    *******9.��������*********\n");
	printf("    **************************\n");
}
void initLLink()//��ʼ��ջ��
{
	if (isEmptyLink() == 1)//�жϵ�ǰ�Ƿ����ջ��
	{
		printf("��ǰ�Ѵ�����������������������ݣ�\n");
		LinkStackPtr p, q;
		p = q = linktop.top;
		for (int i = linktop.count; i >= 1; i--)
		{
			printf("���������Ϊ%d�����ݣ�\n", i);
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
	printf("������ջ���Ľڵ㣺\n");
	int a;
	scanf("%d", &a);
	getchar();
	linktop.count = a;
	LinkStackPtr p=NULL,q=NULL;
	for (int i = 1; i <= linktop.count; i++)
	{
		printf("��%d���ڵ�����ݣ�\n", i);
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
		p = (LinkStackPtr)malloc(sizeof(link));//ջ��������
		p->next = q;
		q = p;
	}
}
int isEmptyLink()//�ж�ջ���Ƿ�Ϊ��
{
	if (linktop.top == NULL)
	{
		printf("ջ��Ϊ��\n");
		return 0;
	}
	printf("ջ����Ϊ��\n");
	return 1;
}
void getTopLLink()//���ջ������
{
	if (isEmptyLink() == 0)
	{
		printf("��ջ��Ϊ�գ�ջ����Ԫ��\n");
		return;
	}
	LinkStackPtr p;
	p = linktop.top;
	printf("ջ��������Ϊ%d��\n",p->data);
}
int clearLLink()//���ջ��
{
	if (isEmptyLink() == 0)
	{
		printf("��ǰ������ջ��\n");
		return 0;
	}
	LinkStackPtr p, q;
	p = q = linktop.top;
	int i;
	for ( i = 1; i <= linktop.count; i++)
	{
		if (i != linktop.count)//�ж��Ƿ�Ϊ���һ���ڵ�
			p = q->next;
		q->data = 0;
		q = p;
	}
	printf("����ɹ�������\n");
	if (i == linktop.count+1)return 1;
}
void destroyLink()//���������ͷ��ڴ�
{
	if (isEmptyLink() == 0)
	{
		printf("������ջ��\n");
		return;
	}
	LinkStackPtr p,q;
	p = q = linktop.top;
	for (int i = 1; i <= linktop.count; i++)
	{
		if (i != linktop.count)//�ж��Ƿ�Ϊ���һ���ڵ�
		p = q->next;
		free(q);
		q = p;
	}
	linktop.top = NULL;
	printf("�ɹ����٣�����\n");
}
void LStackLink()//���ջ�ĳ���
{
	printf("ջ�ĳ���Ϊ%d\n", linktop.count);
}
void pushLLink()//��ջ
{
	if (isEmptyLink == 0)//�ж�ջ���Ƿ�Ϊ��
	{
		printf("��ջΪ�գ����ȳ�ʼ��ջ��\n");
		return;
	}
	printf("�������µĽڵ�����ݣ�\n");
	int a;
	scanf("%d", &a);
	getchar();
	linktop.count++;//ջ���ĳ��ȼ�һ
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(link));
	p->next = linktop.top;
	p->data = a;
	linktop.top = p;//ջ������ͷ�ı�
	printf("��ջ�ɹ�������\n");
}
void popLLink()//��ջ
{
	if (isEmptyLink == 0)//�ж�ջ���Ƿ�Ϊ��
	{
		printf("��ջΪ�գ��޷���ջ\n");
		return;
	}
	LinkStackPtr p = linktop.top;
	if (linktop.count == 0)
	{
		printf("��ջ���Ѳ������κ�Ԫ�أ��޷���ջ������\n");
		return;
	}
	linktop.top = linktop.top->next;
	free(p);
	linktop.count--;//ջ���ڵ��һ
	printf("��ջ�ɹ�������\n");
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
			initLLink();//��ʼ��ջ��
			break;
		case 2:
			isEmptyLink();//�ж��Ƿ�Ϊ��
			break;
		case 3:
			getTopLLink();//ջ��Ԫ��
			break;
		case 4:
			clearLLink();//����ջ��
			break;
		case 5:
			destroyLink();//����ջ��
			break;
		case 6:
			LStackLink();//���ջ�ĳ���
			break;
		case 7:
			pushLLink();//��ջ
			break;
		case 8:
			popLLink();//��ջ
			break;
		case 9:
			goto tiao;
		default:
			printf("������������󣡣���");
		}
		printf("�밴���������....");
		getchar();
		system("cls");
	}
tiao:
	;
}