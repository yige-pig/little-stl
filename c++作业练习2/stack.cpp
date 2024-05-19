#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
#include<iostream>

ArrStack::ArrStack() {
	this->size = 0;
}

ArrStack::~ArrStack() {

}

bool ArrStack::push(int n) {
	if (is_full()) {
		return false;
	}
	arr[size] = n;
	size++;	
	return true;				
}

bool ArrStack::pop(int& n) {
	if(is_empty()) {
		return false;
	}
	n = arr[size - 1];
	size--;
	return true;
}

bool ArrStack::is_full() const {
	if(size== ARR_MAX) {
		return true;
	}
	return false;
}

bool ArrStack::is_empty() const {
	if (size == 0) {
		return true;
	}
	return false;
}

void ArrStack::print(void) const {
	for (int i = size - 1; i >= 0; i--) {
		std::cout << arr[i] << " ";
	}
}

ArrStack& ArrStack::operator+(int n) {
	push(n);
	return *this;
}

ArrStack& ArrStack::operator-(int& n) {
	pop(n);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ArrStack& stk) { //非成员函数可以访问类的私有成员？friend
	for (int i = 0; i < stk.size; i++) {
		os << stk.arr[i] << " ";
	}
	return os;
}


ListStack::ListStack() {
	this->head = NULL;
	this->tail = NULL;
}

ListStack::ListStack(int arr[], int num) {
	head = new Node(arr[0]);
	Node* pre = head;
	for (int i = 1; i < num - 1; i++) {
		Node* cur = new Node(arr[i]);
		cur->prev = pre;
		pre->next = cur;
		pre = cur;
	}
	Node* tailNode = new Node(arr[num - 1]);
	tailNode->prev = pre;
	pre->next = tailNode;
	tail = tailNode;
}

ListStack::~ListStack() {
	Node* cur = head;
	while (cur) {
		Node* temp = cur->next;
		delete(cur);
		cur = temp;
	}
}

bool ListStack::push(int n) {
	Node* newNode = new Node(n);
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

bool ListStack::pop(int& n) {
	if (head == NULL) {
		return false;
	}
	n = tail->data;
	Node* temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete(temp);
	return true;
}

ListStack& ListStack::operator+(int n) {
	push(n);
	return *this;
}

ListStack& ListStack::operator-(int& n) {
	pop(n);
	return *this;
}

bool ListStack::is_empty() const {
	if (head == NULL) {
		return true;
	}
	return false;
}

int ListStack::get_size() const {
	Node* cur = head;
	int count = 0;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

void ListStack::print(void) const {
	Node* cur = head;
	while (cur) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
}

std::ostream& operator<<(std::ostream& os, const ListStack& stk) {
	Node*cur = stk.head;
	while (cur) {
		os<< cur->data << " ";
		cur = cur->next;
	}
	return os;
}