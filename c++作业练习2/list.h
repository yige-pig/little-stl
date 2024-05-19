#pragma once

//˫������
class Node {
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data);
};

class List {
public:
	List();
	List(int arr[], int num);
	void append(int n);//׷��
	void prepend(int n);//ǰ��
	bool delete_left(int& n);//ɾ����һ���ڵ�
	bool delete_right(int& n);//ɾ�����һ���ڵ�
	int length(void);//����������
	void print(void);//��ӡ����
	//�������е�һ��otӦ�������ã���Ϊ std::ostream �ǲ��ɸ��Ƶģ�ֻ��ͨ�����ý��д��ݣ���ȷ����ȷ�������ݺ�״̬ά����
	friend std::ostream &operator<<(std::ostream &ot, const List& lis);//Ϊʲô����friend,ΪʲôҪ&��ΪʲôҪconst
	~List();//Ϊʲôostreamǰ�治��Ҫ��std::
private:
	Node* head;
	Node* tail;
	int len;
};	