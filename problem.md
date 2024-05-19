friend std::ostream& operator<<(std::ostream &ot, const List& lis);
参数表中第一个ot应该是引用，因为 std::ostream 是不可复制的，只能通过引用进行传递，以确保正确的流传递和状态维护。
要访问类的私有成员时，非成员函数重载运算符必须声明为友元函数
因为参数表中第一个ot是引用，所以返回值也必须是引用
void List::append(int n) {**//当链表为空时，head和tail不能访问，所以要判断**
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
bool List::delete_left(int& n) {
	if(!this->head) {
		return false;
	}
	n = this->head->data;
	Node* temp = head;
	head=head->next;
	delete(temp);   **//不能这么写delete(head->prev);因为head可能为空**
	if(head)head->prev = NULL;
	else tail = NULL;
	this->len--;
	return true;
}
List::~List() {
	Node* cur = head;
	while (cur) {
		Node* temp = cur;**//删除必须用temp**
		cur = cur->next;**// cur = cur->next;与delete(temp);顺序不能颠倒**
		delete(temp);
	}
}
*其他文件引入头文件时： #include "list.h" //不能写成#include<list.h>，因为list.h不在标准库中

static constexpr int ARR_MAX = 1000;//定义常量表达式
*bool is_full() const;//const表示该函数不会修改成员变量

*inline 的方法通常在类定义中实现。如果在类定义之外实现 inline 方法，则需要确保其定义在头文件中且与类定义在同一个编译单元中。
