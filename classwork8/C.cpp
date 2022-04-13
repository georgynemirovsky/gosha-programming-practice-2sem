#include <iostream>

using namespace std;


struct Node
{
    int field;
    Node* next;
};


void add_node(Node** head_ptr) {
    Node *current = *head_ptr;
    if (current != nullptr) {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node;
        current->next->next = nullptr;
        cin >> current->next->field;
    } else {
        (*head_ptr) = new Node;
        (*head_ptr)->next = nullptr;
        cin >> (*head_ptr)->field;
    }
}


void pop_element(Node **head_ptr, int index) {
    int i = 0;
    Node *current = *head_ptr;
    Node *prev = nullptr;
    if (index == 1) {
        (*head_ptr) = current->next;
        delete current;
    } else {
        while (i < index - 1 && current->next != nullptr) {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;
        delete current;
    }
}


auto new_list(int n) {
    Node *head_ptr = nullptr;
    for (int i = 0; i < n; i++) {
        add_node(&head_ptr);
    }
    return head_ptr;
}


void print_list(Node** head_ptr) {
    Node *current = *head_ptr;
    while ((current) != nullptr) {
        cout << current->field << " ";
        current = current->next;
    }
    cout << endl;
}


void delete_list(Node** head_ptr) {
    Node *current = (*head_ptr);
    Node *prev = nullptr;
    while (current != nullptr)
    {
        Node *current = prev;
        current = current->next;
        delete prev;
    }
    *head_ptr = nullptr;
}


auto reverse(Node** head_ptr)
{
    Node *prhead = nullptr;
    while ((*head_ptr) != nullptr)
    {
        Node *p = (*head_ptr)->next;
        (*head_ptr)->next = prhead;
        prhead = (*head_ptr);
        (*head_ptr) = p;
    }
    return prhead;
}


int main()
{
    int n = 0;
    cin >> n;
    Node *A = new_list(n);
    A = reverse(&A);
    print_list(&A);
    delete_list(&A);
    delete A;
    return 0;
}
