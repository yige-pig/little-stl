#pragma once

class ArrQueue {
private:
	static constexpr int ARR_MAX = 1000;
	int arr[ARR_MAX];
	int size;
	int front;
	int end;
public:
	ArrQueue();
	bool enqueue(int n);
	bool dequeue(int& n);
	bool is_full() const;
	bool is_empty() const;
	inline int get_size() const;
	void print(void) const;
	ArrQueue& operator+(int n);
	ArrQueue& operator-(int& n);
	friend std::ostream& operator<<(std::ostream& os, const ArrQueue& q);	
	~ArrQueue();
};

inline int ArrQueue::get_size() const {
	return size;
}

class ListQueue: public ArrQueue{
private:
	List lis;
	Node* head;
	Node* tail;
public:
	ListQueue();
	ListQueue(int arr[], int num);
	bool enqueue(int n);
	bool dequeue(int& n);
	bool is_empty() const;
	inline int get_size() const;
	void print(void) const;
	ListQueue& operator+(int n);
	ListQueue& operator-(int& n);
	friend std::ostream& operator<<(std::ostream& os, const ListQueue& q);
	~ListQueue();
};

inline int ListQueue::get_size() const {
	int count = 0;
	Node* p = head;
	while (p != nullptr) {
		count++;
		p = p->next;
	}
	return count;
}