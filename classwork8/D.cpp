#include <iostream>

using namespace std;


struct Node {
    int field;
    Node* next;
};


struct List {
    Node* head;


    List () {
        head = nullptr;
    }


    void add_node() {
        Node *current = head;
        if (current != nullptr) {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node;
            current->next->next = nullptr;
            cin >> current->next->field;
        } else {
            head = new Node;
            head->next = nullptr;
            cin >> head->field;
        }
    }


    auto new_list(int n) {
        for (int i = 0; i < n; i++) {
            add_node();
        }
        return head;
    }


    void delete_list() {
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr)
        {
            Node *current = prev;
            current = current->next;
            delete prev;
        }
        head = nullptr;
    }
};


int half_poisk(Node** head_ptr) {
    Node* current = *head_ptr;
    int i = 1;
    while (current->next->next != nullptr && current->next != nullptr && current != nullptr) {
        if (current->next->field == 1) {
            if (current->field == 1) {
                return i;
            } else {
                return i + 1;
            }
        } else {
            current = current->next->next;
            i += 2;
        }
    }
    return -1;
}

int main() {
    int n = 0;
    cin >> n;
    List A;
    Node* head_ptr = A.new_list(n);

    cout << half_poisk(&head_ptr);

    A.delete_list();
    return 0;
}
