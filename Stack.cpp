#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int elemtype;
//˳��ջ
typedef struct {
	elemtype* base;
	elemtype* top;
	int stacksize;
}SqStack;

//ջ�ĳ�ʼ��
bool InitStack(SqStack& s)
{
	s.base = new elemtype [MAXSIZE];
	if (!s.base)
	{
		cerr << " failed to get memory" << endl;
		return false;
	}
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return true;
}

//ѹջ
bool Push(SqStack& S, elemtype& e)
{
	if (S.top - S.base == S.stacksize)
	{
		cerr << "full of stack" << endl;
		return false;
	}
	*S.top = e;
	S.top++;
	return true;
}

//����ջ
bool CreatStack(SqStack& S, const int n)
{
	for (int i = 0; i < n; i++)
	{
		elemtype temp;
		cin >> temp;
		Push(S, temp);
		if (!Push(S, temp))
		{
			cerr<<"error happend at-"<<i<<endl;
			return false;
		}
	}
	return true;
}

//�ж��Ƿ�Ϊ��
bool IsEmpty(SqStack& S)
{
	if (S.base == S.top)
	{
		return false;
	}
	else
		return true;
}

//��ջ
bool Pop(SqStack& S, elemtype& e)
{
	if (!IsEmpty(S))
	{
		cerr << "error" << endl;
		return false;
	}
	S.top--;
	e = *S.top;
	return true;
}

//��ȡ˳��
int StackLength(SqStack& S)
{
	return static_cast<int>(S.top - S.base);
}

//���
bool ClearStack(SqStack& S)
{
	if (S.base)
	{
		S.top = S.base;
		return true;
	}
	else
	{
		return false;
	}
}

//����
void DestoyStack(SqStack& S)
{
	if (S.base)
	{
		delete[] S.base;
		S.stacksize = 0;
		S.base = S.top = nullptr;
	}
}

//��ջ
typedef struct StackNode
{
	elemtype data;
	StackNode* next;
} *LinkStack;

//ջ�ĳ�ʼ��


void initStack(LinkStack& s)
{
	s = NULL;
}

//�ж��Ƿ�Ϊ��
int stackEmpty(LinkStack s)
{
	if (s == NULL)
		return 1;
	return 0;
}

//�жϳ���
int stackLength(LinkStack s)
{
	int sum = 0;
	LinkStack temp = s;
	while (temp != NULL)
	{
		sum++;
		temp = temp->next;
	}
	return sum;
}

//ѹջ
void push(LinkStack& s, int e)
{
	StackNode* p = new StackNode;
	p->data = e;
	p->next = NULL;
	if (s == NULL)
		s = p;
	else
	{
		p->next = s;
		s = p;
	}
}

//��ջ 
void pop(LinkStack& s, int& e)
{
	StackNode* p = new StackNode;
	if (s == NULL)
	{
		cout << "ջΪ�գ��޷�����" << endl;
	}
	else
	{
		p = s;
		e = p->data;
		s = s->next;
		delete p;
		cout << "�ɹ�����ջ��Ԫ��" << endl;
	}
}

//��ջ��Ԫ��
int top(LinkStack s)
{
	if (s == NULL)
		return -1;
	return s->data;
}

//���ջ
bool ClearStack(LinkStack& S)
{
	if (!S)
	{
		cerr << "empty Stack" << endl;
		return false;
	}
	StackNode* q, * p = S;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	S = nullptr;
	return true;
}

//����ջ����ջ��������������

bool DestoryStack(LinkStack& S)
{
	if (S)
	{
		cerr << "error" << endl;
		return false;
	}
	while (S)
	{
		StackNode* temp = S;
		S = S->next;
		delete temp;
	}
	return true;
}













int mian()
{

	return 0;
}