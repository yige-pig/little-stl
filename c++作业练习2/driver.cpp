#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"driver.h"

// Compilation instructions:
// g++ -std=c++17 -o D:\c++\c++作业练习2\x64\Debug\c++作业练习2 list.cpp stack.cpp queue.cpp driver.cpp



int main() {
	//test list
	cout << "————————以下为链表测试————————————" << endl;

	int arr[] = { 1,2,3,4,5 };
	int temp;
	List lis;
	lis.append(1);
	cout << lis << endl; //test append、重载<<
	lis.prepend(2);
	cout << lis << endl;//test prepend
	lis.delete_left(temp);
	cout << "链表元素为："<< lis << "删除的第一个数为：" << temp << endl;//test delete_left
	lis.delete_right(temp);
	cout << "链表元素为：" << lis << "删除的第一个数为：" << temp << endl;//test delete_right
	cout << "链表长度为：" << lis.length() << endl;//test length
	List lis1(arr, 5);
	cout << lis1 << endl;//test 构造函数 print
	

	//test stack
	//test ArrStack
	cout << "-------以下为ArrStack测试------" << endl;

	ArrStack stack;
	int temp1;
	stack.push(1);//test push
	stack.push(2);
	cout << stack << endl;//test 重载<<
	stack.pop(temp1);//test pop
	cout << "stack元素为：" << stack << " 弹出元素为：" << temp1 << endl;
	cout << "stack是否为空：" << stack.is_empty() << endl;//test is_empty
	cout << "stack是否为满：" << stack.is_full() << endl;//test is_full
	cout << "stack的大小为：" << stack.get_size() << endl;//test get_size
	stack + 3;//test operator+
	cout << stack << endl;
	stack - temp1;//test operator-
	cout << "stack元素为：" << stack << " 弹出元素为：" << temp1 << endl;
	stack.print();//test print
	cout << endl;


	//test ListStack	
	cout << "-------以下为ListStack测试------" << endl;

	int temp2;
	ListStack stack1;
	stack1.push(1);//test push
	stack1.push(2);
	cout << stack1 << endl;//test 重载<<
	stack1.pop(temp2);//test pop
	cout << "stack1元素为：" << stack1 << " 弹出元素为：" << temp2 << endl;
	cout << "stack1是否为空：" << stack1.is_empty() << endl;//test is_empty
	cout << "stack1的大小为：" << stack1.get_size() << endl;//test get_size
	stack1 + 3;//test operator+
	cout << stack1 << endl;
	stack1 - temp2;//test operator-
	cout << "stack1元素为：" << stack1 << " 弹出元素为：" << temp2 << endl;
	stack1.print();//test print
	cout << endl;


	//test queue
	//test ArrQueue
	cout << "-------以下为ArrQueue测试------" << endl;

	ArrQueue queue;
	int temp3;
	queue.enqueue(1);//test enqueue
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	cout << queue << endl;//test 重载<<
	queue.dequeue(temp3);//test dequeue
	cout << "queue元素为：" << queue << " 弹出元素为：" << temp3 << endl;
	cout << "queue是否为空：" << queue.is_empty() << endl;//test is_empty
	cout << "queue是否为满：" << queue.is_full() << endl;//test is_full
	cout << "queue的大小为：" << queue.get_size() << endl;//test get_size
	queue + 5;//test operator+
	cout << queue << endl;
	queue - temp3;//test operator-
	cout << "queue元素为：" << queue << " 弹出元素为：" << temp3 << endl;
	queue.print();//test print
	cout << endl;


	cout << "-------以下为ListQueue测试------" << endl;

	int temp4;
	ListQueue queue1;
	queue1.enqueue(1);//test enqueue
	queue1.enqueue(2);
	queue1.enqueue(3);
	queue1.enqueue(4);
	cout << queue1 << endl;//test 重载<<
	queue1.dequeue(temp4);//test dequeue
	cout << "queue1元素为：" << queue1 << " 弹出元素为：" << temp4 << endl;
	cout << "queue1是否为空：" << queue1.is_empty() << endl;//test is_empty
	cout << "queue1的大小为：" << queue1.get_size() << endl;//test get_size
	queue1 + 5;//test operator+
	cout << queue1 << endl;
	queue1 - temp4;//test operator-
	cout << "queue1元素为：" << queue1 << " 弹出元素为：" << temp4 << endl;
	queue1.print();//test print
	cout << endl;

	system("pause");
	return 0;
}
