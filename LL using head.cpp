#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
protected:
	Node* head;

	virtual void insertAtHead(int) = 0;
	virtual void insertAtTail(int) = 0;
	virtual void display() = 0;
	virtual void enqueue(int) = 0;
	virtual int dequeue() = 0;
	virtual void push(int) = 0;
	virtual int pop() = 0;

public:
	LinkedList();
};

LinkedList::LinkedList() {
	head = nullptr; 
}

class myLL :public LinkedList {

public:
	void insertAtHead(int);
	void insertAtTail(int);
	void display();
	void enqueue(int);
	int dequeue();
	void push(int);
	int pop();
};

void myLL::insertAtHead(int value) {
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr) {
		head = nn;
	}
	else {
		nn->next = head;
		head = nn;
	}
}

void myLL::insertAtTail(int value) {
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr) {
		head = nn;
		return;
	}

	Node* temp = head;
	while (1) {
		if (temp->next == nullptr)
			break;
		else
			temp = temp->next;
	}
	temp->next = nn;
}

void myLL::display() {
	Node* temp = head;
	while (1) {
		cout << temp->data << endl;
		temp = temp->next;

		if (temp == nullptr)
			break;
	}
}

void myLL::enqueue(int value) {
	insertAtTail(value);
}

int myLL::dequeue() {
	if (head == nullptr) {
		cout << "LL is empty." << endl;
		return -1; 
	}

	if (head->next == nullptr) {
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else {
		Node* temp = head;
		int returningValue = head->data;
		head = head->next;
		delete temp;
		temp = nullptr;
		return returningValue;
	}
}

void myLL::push(int value) {
	insertAtHead(value);
}

int myLL::pop() {
	if (head == nullptr) {
		cout << "LL is empty." << endl;
		return -1; 
	}

	if (head->next == nullptr) {
		int returningValue = head->data;
		delete head;
		head = nullptr;
		return returningValue;
	}
	else {
		Node* temp = head;
		int returningValue = head->data;
		head = head->next;
		delete temp;
		temp = nullptr;
		return returningValue;
	}
}

int main() {
	myLL list;
	list.enqueue(10);
	list.enqueue(20);
	list.enqueue(30);
	list.display();  // 10 20 30

	cout << "Dequeued: " << list.dequeue() << endl;  // 10
	list.display();  // 20 30

	list.push(5);
	list.display();  // 5 20 30

	cout << "Popped: " << list.pop() << endl;  //5
	list.display();  // 20 30
}
