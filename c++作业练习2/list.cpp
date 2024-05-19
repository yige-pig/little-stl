#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"list.h"

Node::Node(int data) {
	this->data = data;
	prev = NULL;
	next = NULL;
}

List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->len = 0;
}

List::List(int arr[], int num) {
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

List::~List() {
	Node* cur = head;
	while (cur) {
		Node* temp = cur;//删除必须用temp
		cur = cur->next;// cur = cur->next;与delete(temp);顺序不能颠倒
		delete(temp);
	}
}

void List::append(int n) {//当链表为空时，head和tail不能访问，所以要判断
	Node* newNode = new Node(n);
	if (!this->tail) {
		this->head = newNode;
		this->tail = newNode;
		this->len++;
		return;
	}
	newNode->prev = this->tail;
	this->tail->next = newNode;
	this->tail = newNode;
	this->len++;
}

void List::prepend(int n) {
	Node* newNode = new Node(n);
	if (!this->head) {
		this->head = newNode;
		this->tail = newNode;
		this->len++;
		return;
	}
	newNode->next = this->head;
	this->head->prev = newNode;
	this->head = newNode;
	this->len++;
}

bool List::delete_left(int& n) {
	if(!this->head) {
		return false;
	}
	n = this->head->data;
	Node* temp = head;
	head=head->next;
	delete(temp);//不能这么写delete(head->prev);因为head可能为空
	if(head)head->prev = NULL;
	else tail = NULL;
	this->len--;
	return true;
}

bool List::delete_right(int& n) {
	if(!this->tail) {
		return false;
	}
	n = this->tail->data;
	Node*temp = tail;
	tail = tail->prev;
	delete(temp);
	if(tail)tail->next = NULL;
	else head = NULL;
	this->len--;
	return true;
}

int List::length(void) {
	Node* dummyHead= new Node(0);
	dummyHead->next = this->head;
	Node* cur = dummyHead;
	int legth = 0;
	while(cur->next) {
		legth++;
		cur = cur->next;
	}
	delete(dummyHead);
	return legth;
}

void List::print(void) {
	Node* cur = this->head;
	while (cur) {
		std::cout << cur->data << " ";//链式编程
		cur = cur->next;
	}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &ot, const List& lis) { //没返回引用就会报错
	Node* cur = lis.head;
	while (cur) {
		ot << cur->data << " ";
		cur = cur->next;
	}
	return ot;
}

