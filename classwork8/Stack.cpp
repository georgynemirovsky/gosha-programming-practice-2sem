#include <iostream>

using namespace std;

struct Node {
    int field;
    Node* next;
};
struct Stack {
    Node *top = new Node;

    Stack(int field) {
        top->next = nullptr;
        top->field = field;
    }

    void push(int field) {
        if (top != nullptr) {
            Node* tmp = new Node;
            tmp->next = top;
            top = tmp;
            tmp->field = field;
        } else {
            Node* tmp = new Node;
            top = tmp;
            top->next = nullptr;
            top->field = field;
        }
    }


    void pop() {
        Node* tmp = top;
        top = top->next;
        delete tmp;
    }


    bool is_empty(){
        if (top == nullptr) {
            return true;
        } else {
            return false;
        }
    }


    int Top() {
        return top->field;
    }


};
int main() {
    Stack st = Stack(1);


    cout << st.is_empty() << endl;
    st.pop();
    cout << st.is_empty() << endl;
    st.push(10);
    cout << st.Top() << endl;
    cout << st.is_empty() << endl;
    st.pop();
    return 0;
}
