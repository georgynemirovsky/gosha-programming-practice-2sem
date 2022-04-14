#include <iostream>
#include <cstring>

using namespace std;


struct Node {
    char field = ' ';
    Node* next;
};


struct List {
    Node* head;

    List() {
        head = nullptr;
    }


    auto add_node(char (&value)) {
        Node *current = head;
        if (current != nullptr) {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node;
            current->next->next = nullptr;
            current->next->field = value;
        } else {
            head = new Node;
            head->next = nullptr;
            head->field = value;
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


int clear_staples(Node** head_ptr) {
    Node* current = *head_ptr;
    int left_staple = 0;
    int right_staple = 0;
    while (current != nullptr) {
        if (current->field == ')') {
            left_staple++;
        } else {
            right_staple++;
        }
        if (right_staple < left_staple) {
            return 1;
        }
        else {
            current = current->next;
        }
    }
    if (right_staple == left_staple) {
        return 0;
    } else {
        return 1;
    }
}


int main() {
    char staples[20];
    List A;
    Node* head_ptr = nullptr;


    cin >> staples;


    for (int i = 0; i < strlen(staples); i++ ) {
        head_ptr = A.add_node(staples[i]);
    }


    cout << clear_staples(&head_ptr) << endl;


    A.delete_list();
    return 0;
}
