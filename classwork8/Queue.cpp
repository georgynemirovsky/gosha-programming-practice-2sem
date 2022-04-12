#include <iostream>


using namespace std;


struct Node {
  int field;
  Node* prev;
  Node* next;
};


struct Queue {
    Node* head;
    Node* tail;


    Queue(int value) {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        head->field = value;
        tail = head;
	}


    void push(int value){
        if (head == nullptr) {
            Node* tmp = new Node;
            tmp->next = nullptr;
            tmp->prev = nullptr;
            tmp->field = value;
            head = tmp;
            tail = tmp;
        } else {
            Node* tmp = new Node;
            tmp->prev = tail;
            tmp->next = nullptr;
            tmp->field = value;
            tail->next = tmp;
            tail = tmp;
        }
    }


    void pop() {
        if (tail->prev != nullptr) {
            Node* tmp = tail;
            tail = tail->prev;
            delete tmp;
        } else {
            Node* tmp = tail;
            tail = nullptr;
            head = nullptr;
            delete tmp;
        }
    }


    bool is_empty() {
        return (head == nullptr);
    }


    int size() {
        Node* current = head;
        int s = 0;
        while (current != nullptr) {
            s++;
            current = current->next;
        }
        return s;
    }
};


int main() {
    Queue q = Queue(1);
    q.push(10);
    cout << (q.head->field) << " " << (q.tail->field) << endl;
    q.pop();
    cout << q.is_empty() << endl;
    q.pop();
    cout << q.is_empty() << endl;
    q.push(10);
    q.push(10);
    q.push(10);
    cout << q.size() << endl;
    return 0;
}
