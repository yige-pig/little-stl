#pragma once

//双向链表
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
	void append(int n);//追加
	void prepend(int n);//前置
	bool delete_left(int& n);//删除第一个节点
	bool delete_right(int& n);//删除最后一个节点
	int length(void);//返回链表长度
	void print(void);//打印链表
	//参数表中第一个ot应该是引用，因为 std::ostream 是不可复制的，只能通过引用进行传递，以确保正确的流传递和状态维护。
	friend std::ostream &operator<<(std::ostream &ot, const List& lis);//为什么必须friend,为什么要&，为什么要const
	~List();//为什么ostream前面不需要加std::
private:
	Node* head;
	Node* tail;
	int len;
};	