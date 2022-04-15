#include<iostream>
using namespace std;
#define ElemType int 
typedef struct linkNode
{
	ElemType data;
	linkNode* next;//链栈的栈顶为链表的s->next;
}LinkNode;
void InitStack(LinkNode*& s)//初始化栈
{
	s = new LinkNode;
	s->next = NULL;
	cout << "初始化栈成功！" << endl;
	return;
}
void DestroyStack(LinkNode*& s)//销毁栈
{
	LinkNode* pre = s, * p = s->next;
	while (p)
	{
		delete(pre);
		pre = p;
		p = p->next;
	}
	delete(pre);
	cout << "栈销毁成功！" << endl;
	return;
}
bool StackEmpty(LinkNode* s)//判断栈是否为空
{
	return(s->next == NULL);
 }
void Push(LinkNode*& s, ElemType e)//进栈
{
	LinkNode* p = new LinkNode;
	p->data = e;
	p->next = s->next;
	s->next = p;
	cout << "元素" << e << "进栈成功！" << endl;
	return;
}
bool Pop(LinkNode*& s, ElemType& e)//出栈
{
	if (s->next == NULL)
		return false;
	LinkNode* p = s->next;
	e = p->data;
	s->next = p->next;
	delete(p);
	cout << "元素" << e << "出栈成功！" << endl;
	return true;
}
bool GetTop(LinkNode* s, ElemType& e)//取栈顶元素
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	cout << "此时栈顶元素为：" << e << endl;
	return true;
}
void SetData(LinkNode*& s)
{
	int data;
	cout << "请输入进栈元素：";
	cin >> data;
	cout << endl;
	Push(s, data);
}
int main()
{
	int e;
	LinkNode* s = NULL;
	InitStack(s);
	if (StackEmpty(s))
		cout << "此时栈为空！" << endl;
	else
		cout << "栈不为空！" << endl;
	SetData(s);
	if (StackEmpty(s))
		cout << "此时栈为空！" << endl;
	else
		cout << "栈不为空！" << endl;
	GetTop(s, e);
	Pop(s, e);
	DestroyStack(s);
	return 0;
}