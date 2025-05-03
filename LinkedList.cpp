#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
protected:
    Node* head;
    Node* tail;

    virtual void InsertAtHead(int) = 0;
    virtual void InsertAtTail(int) = 0;
    virtual bool isEmpty() = 0;
    virtual int deletefromHead() = 0;
    virtual int deletefromTail() = 0;
    virtual void insertSorted(int) = 0;
    virtual bool deleteValue(int) = 0;
    virtual void display() = 0;
    virtual bool search(int) = 0;
    virtual void deleteduplicateValues() = 0;
    virtual void sortLL() = 0;
public:
    LinkedList();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

class myLL : public LinkedList {
public:
    void InsertAtHead(int);
    void InsertAtTail(int);
    bool isEmpty();
    int deletefromHead();
    int deletefromTail();
    void insertSorted(int);
    bool deleteValue(int);
    void display();
    bool search(int);
    void deleteduplicateValues();
    void sortLL();
};

bool myLL::isEmpty() {
    return head == nullptr;
}

void myLL::InsertAtHead(int value) {
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        head = nn;
        tail = nn;
    }
    else {
        nn->next = head;
        head = nn;
    }
}

void myLL::InsertAtTail(int value) {
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;

    if (isEmpty()) {
        head = nn;
        tail = nn;
    }
    else {
        tail->next = nn;
        tail = nn;
    }
}

void myLL::display() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
    }
    else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int myLL::deletefromHead() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return -1;  // Indicating failure
    }

    int returningValue = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return returningValue;
}

int myLL::deletefromTail() {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return -1;  // Indicating failure
    }

    Node* temp = head;
    while (temp != nullptr && temp->next != tail) {
        temp = temp->next;
    }

    int returningValue = tail->data;
    delete tail;
    tail = temp;
    if (temp != nullptr) {
        temp->next = nullptr;
    }
    return returningValue;
}

bool myLL::search(int value) {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return false;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void myLL::insertSorted(int value) {
    if (isEmpty()) {
        Node* nn = new Node;
        nn->data = value;
        nn->next = nullptr;
        head = nn;
        tail = nn;
    }
    else if (value <= head->data) {
        InsertAtHead(value);
    }
    else if (value >= tail->data) {
        InsertAtTail(value);
    }
    else {
        Node* nn = new Node;
        nn->data = value;
        nn->next = nullptr;
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data < value) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
}

bool myLL::deleteValue(int value) {
    if (isEmpty()) {
        cout << "LL is empty." << endl;
        return false;
    }

    if (head->data == value) {
        deletefromHead();
        return true;
    }

    if (tail->data == value) {
        deletefromTail();
        return true;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        return false;  // Value not found
    }

    Node* t2 = temp->next;
    temp->next = temp->next->next;
    delete t2;
    return true;
}

void myLL::deleteduplicateValues() {

    if (isEmpty())
        cout << "LL is empty." << endl;

    else {

        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {

            if (temp->data == temp->next->data) {

                Node* tobeDeleted = temp->next;
                temp->next = temp->next->next;  //Skipped the node that we want to delete
                delete tobeDeleted;
            }

            else
                temp = temp->next;

        }
    }
}

void myLL::sortLL() {

    if (isEmpty())
        cout << "LL is empty." << endl;

    else {


        Node* temp = head;
        Node* temp2;
        while (temp != nullptr) {

            temp2 = temp->next;
            while (temp2 != nullptr) {

                if (temp->data > temp2->data) {

                    int t = temp2->data;
                    temp2->data = temp->data;
                    temp->data = t;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

    }
}


int main() {
    myLL obj;

    obj.InsertAtHead(55);
    obj.InsertAtTail(22);
    obj.InsertAtTail(29);
    obj.InsertAtHead(90);
    obj.InsertAtTail(2);
    cout << "Display: " << endl;
    obj.display();

    cout << "After deleting the duplicate values in the list:" << endl;
    obj.deleteduplicateValues();

    cout << "And after sorting:" << endl;
    obj.sortLL();
    obj.display();
    return 0;
}
