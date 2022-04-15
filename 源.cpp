#include<iostream>
using namespace std;
#define ElemType int 
typedef struct linkNode
{
	ElemType data;
	linkNode* next;//��ջ��ջ��Ϊ�����s->next;
}LinkNode;
void InitStack(LinkNode*& s)//��ʼ��ջ
{
	s = new LinkNode;
	s->next = NULL;
	cout << "��ʼ��ջ�ɹ���" << endl;
	return;
}
void DestroyStack(LinkNode*& s)//����ջ
{
	LinkNode* pre = s, * p = s->next;
	while (p)
	{
		delete(pre);
		pre = p;
		p = p->next;
	}
	delete(pre);
	cout << "ջ���ٳɹ���" << endl;
	return;
}
bool StackEmpty(LinkNode* s)//�ж�ջ�Ƿ�Ϊ��
{
	return(s->next == NULL);
 }
void Push(LinkNode*& s, ElemType e)//��ջ
{
	LinkNode* p = new LinkNode;
	p->data = e;
	p->next = s->next;
	s->next = p;
	cout << "Ԫ��" << e << "��ջ�ɹ���" << endl;
	return;
}
bool Pop(LinkNode*& s, ElemType& e)//��ջ
{
	if (s->next == NULL)
		return false;
	LinkNode* p = s->next;
	e = p->data;
	s->next = p->next;
	delete(p);
	cout << "Ԫ��" << e << "��ջ�ɹ���" << endl;
	return true;
}
bool GetTop(LinkNode* s, ElemType& e)//ȡջ��Ԫ��
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	cout << "��ʱջ��Ԫ��Ϊ��" << e << endl;
	return true;
}
void SetData(LinkNode*& s)
{
	int data;
	cout << "�������ջԪ�أ�";
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
		cout << "��ʱջΪ�գ�" << endl;
	else
		cout << "ջ��Ϊ�գ�" << endl;
	SetData(s);
	if (StackEmpty(s))
		cout << "��ʱջΪ�գ�" << endl;
	else
		cout << "ջ��Ϊ�գ�" << endl;
	GetTop(s, e);
	Pop(s, e);
	DestroyStack(s);
	return 0;
}