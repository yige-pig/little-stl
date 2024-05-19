#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"list.h"
#include"queue.h"
#include"stack.h"

ArrQueue::ArrQueue() {
	size = 0;
	front = -1;
	end = -1;
}

bool ArrQueue::enqueue(int n) {
	if (is_full()) {
		return false;
	}
	end = (end + 1) % ARR_MAX;
	arr[end] = n;
	size++;
	return true;
}

bool ArrQueue::dequeue(int& n) {
	if (is_empty()) {
		return false;
	}
	front = (front + 1) % ARR_MAX;
	n = arr[front]; n = arr[front];
	size--;
	return true;
}

bool ArrQueue::is_full() const {
	if (size == ARR_MAX) {
		return true;
	}
	return false;
}

bool ArrQueue::is_empty() const {
	if (size == 0) return true;
	return false;
}

void ArrQueue::print(void) const {
	std::cout << *this;
}

ArrQueue& ArrQueue::operator+(int n) {
	enqueue(n);
	return *this;
}

ArrQueue& ArrQueue::operator-(int& n) {
	dequeue(n);
	return *this;
}

std::ostream&operator<<(std::ostream& os, const ArrQueue& q) {
	if (q.is_empty()) {
		return os;
	}
	for (int i = 0; i < q.size; i++) {
		os << q.arr[(q.front + i + 1 ) % q.ARR_MAX] << " ";
	}
	return os;
}

ArrQueue::~ArrQueue() {

}


ListQueue::ListQueue() {
	head = tail = nullptr;
}

ListQueue::ListQueue(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		enqueue(arr[i]);
	}
}

bool ListQueue::enqueue(int n) {
	Node* newNode = new Node(n);
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

bool ListQueue::dequeue(int& n) {
	if (!head) {
		return false;
	}
	n = head->data;
	Node* temp = head;
	head = head->next;
	delete temp;
	head->prev = nullptr;
	return true;
}

ListQueue::~ListQueue() {
	while (!head) {
		Node*temp = head;
		head = head->next;	
		delete temp;
	}
}

bool ListQueue::is_empty() const {
	if(!head)return true;
	return false;
}

void ListQueue::print(void) const {
	std::cout << *this;
}

ListQueue& ListQueue::operator+(int n) {
	enqueue(n);
	return *this;
}

ListQueue& ListQueue::operator-(int& n) {
	dequeue(n);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ListQueue& q) {
	Node* cur = q.head;
	while (cur) {
		os << cur->data << " ";
		cur = cur->next;
	}
	return os;
}