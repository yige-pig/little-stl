#pragma once
#include<vector>
#include<iostream>
#include "list.h" //����д��#include<list.h>����Ϊlist.h���ڱ�׼����

class ArrStack {
private:
	int size;
	static constexpr int ARR_MAX = 1000;//���峣�����ʽ
	int arr[ARR_MAX];
public:
	ArrStack();
	bool push(int n);
	bool pop(int& n);
	bool is_full() const;//const��ʾ�ú��������޸ĳ�Ա����
	bool is_empty() const;
	inline int get_size() const;
	void print(void) const;
	ArrStack& operator+(int n);
	ArrStack& operator-(int& n);
	friend std::ostream & operator<<(std::ostream& os, const ArrStack& stk); 
	~ArrStack();	
};

//inline �ķ���ͨ�����ඨ����ʵ�֡�������ඨ��֮��ʵ�� inline ����������Ҫȷ���䶨����ͷ�ļ��������ඨ����ͬһ�����뵥Ԫ�С�
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