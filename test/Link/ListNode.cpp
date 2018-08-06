#include"ListNode.h"
Node ListNode::insertAsPre(int data)
{
	//ͨ������һ����� ʵ�� x.Pred��x.Succ
	Node x = new ListNode(data, Pred, this);
	Pred->Succ = x;
	Pred = x;
	return x;
}
Node ListNode::insertAsSucc(int data)
{
	Node x = new ListNode(data, this, Succ);
	Succ->Pred = x;
	Succ = x;
	return x;
}
Node ListNode::my_insertAsPre(int data)
{
	Node x = new ListNode(data, Pred, this);
	x->Succ->Pred = x;
	x->Pred->Succ = x;
	return x;
}