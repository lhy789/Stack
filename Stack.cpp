#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int elemtype;
//顺序栈
typedef struct {
	elemtype* base;
	elemtype* top;
	int stacksize;
}SqStack;

//栈的初始化
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

//压栈
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

//创建栈
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

//判断是否为空
bool IsEmpty(SqStack& S)
{
	if (S.base == S.top)
	{
		return false;
	}
	else
		return true;
}

//出栈
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

//获取顺序
int StackLength(SqStack& S)
{
	return static_cast<int>(S.top - S.base);
}

//清空
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

//销毁
void DestoyStack(SqStack& S)
{
	if (S.base)
	{
		delete[] S.base;
		S.stacksize = 0;
		S.base = S.top = nullptr;
	}
}

//链栈
typedef struct StackNode
{
	elemtype data;
	StackNode* next;
} *LinkStack;

//栈的初始化


void initStack(LinkStack& s)
{
	s = NULL;
}

//判断是否为空
int stackEmpty(LinkStack s)
{
	if (s == NULL)
		return 1;
	return 0;
}

//判断长度
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

//压栈
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

//出栈 
void pop(LinkStack& s, int& e)
{
	StackNode* p = new StackNode;
	if (s == NULL)
	{
		cout << "栈为空，无法弹出" << endl;
	}
	else
	{
		p = s;
		e = p->data;
		s = s->next;
		delete p;
		cout << "成功弹出栈顶元素" << endl;
	}
}

//求栈顶元素
int top(LinkStack s)
{
	if (s == NULL)
		return -1;
	return s->data;
}

//清空栈
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

//销毁栈（消栈哈哈哈！！！）

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