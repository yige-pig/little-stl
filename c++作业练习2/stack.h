#pragma once
#include<vector>
#include<iostream>
#include "list.h" //不能写成#include<list.h>，因为list.h不在标准库中

class ArrStack {
private:
	int size;
	static constexpr int ARR_MAX = 1000;//定义常量表达式
	int arr[ARR_MAX];
public:
	ArrStack();
	bool push(int n);
	bool pop(int& n);
	bool is_full() const;//const表示该函数不会修改成员变量
	bool is_empty() const;
	inline int get_size() const;
	void print(void) const;
	ArrStack& operator+(int n);
	ArrStack& operator-(int& n);
	friend std::ostream & operator<<(std::ostream& os, const ArrStack& stk); 
	~ArrStack();	
};

//inline 的方法通常在类定义中实现。如果在类定义之外实现 inline 方法，则需要确保其定义在头文件中且与类定义在同一个编译单元中。
inline int ArrStack::get_size() const {
	return size;
}


class ListStack:public ArrStack {
private:
	List lis;
	Node* head;
	Node* tail;
public:
	ListStack();
	ListStack(int arr[], int num);
	bool push(int n);
	bool pop(int& n);
	bool is_empty() const;
	int get_size() const;
	void print(void) const;
	ListStack& operator+(int n);
	ListStack& operator-(int& n);
	friend std::ostream& operator<<(std::ostream& os, const ListStack& stk);
	~ListStack();
};