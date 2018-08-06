#include"ListNode.h"
class List
{
private:
	Node header;
	Node tailer;
	int _size;
protected:
	void init();
	int rangeCheck(int r) const
	{
		return r > _size ? 1 : 0;
	}
public:
	//���캯��
	List(){ init(); }
	List(List const& L); 
	//ֻ���ӿ�
	Node frist() const{ return header->Succ; }
	Node last() const{ return tailer->Pred; }
	//д��ӿ�
	Node insertAsFrist(int data);//�����׽ڵ�  header ͷ
	Node insertAsLast(int data);//����β�ڵ�   tailer ĩ
	Node insertAsB(Node p, int data);//�ڸýڵ�ǰ����ڵ�
	Node insertAsA(Node p, int data);//�ڸýڵ�����ڵ�
	void copyNode(Node p, int n);//�ӽڵ�p��ʼ����
	// Rank r
	int operator[]  (int r) const
	{
		if (rangeCheck(r))
		{
			return -1;
		}
		Node p = frist();
		while (r--)
		{
			p->Succ;
		}
		return p->data;
	}
	int remove(Node p);
};
