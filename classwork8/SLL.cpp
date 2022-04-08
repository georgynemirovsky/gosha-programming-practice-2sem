#include <iostream>

using namespace std;


struct Node {
  int field;
  Node* next;
};


void add_node(Node** head_ptr, int value) {
    Node *current = *head_ptr;
    if (current != nullptr) {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node;
        current->next->next = nullptr;
        current->next->field = value;
    } else {
        (*head_ptr) = new Node;
        (*head_ptr)->next = nullptr;
        (*head_ptr)->field = value;
    }
}


void delete_by_value(Node** head_ptr, int value) {
  Node *current = *head_ptr;
  Node *prev = nullptr;
  while (current != nullptr) {
    if (current->field == value) {
      break;
    }
    prev = current;
    current = current->next;
  }
  prev->next = current->next;
  delete current;
}


void pop(Node **head_ptr) {
    Node *current = *head_ptr;
    if (current->next == nullptr) {
        *head_ptr = nullptr;
    } else {
        while (current->next->next != nullptr) {
        current = current->next;
        }
        current->next = nullptr;
    }
}


void pop_element(Node **head_ptr) {
    int index = 0;
    int i = 0;
    Node *current = *head_ptr;
    Node *prev = nullptr;
    cout << "Enter index" << endl;
    cin >> index;
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


void add_element(Node **head_ptr) {
    int index = 0;
    int number = 0;
    Node *current = *head_ptr;
    cout << "Enter number and index" << endl;
    cin >> number >> index;
    if (index == 1) {
        Node* tmp = new Node;
        tmp->next = (*head_ptr);
        tmp->field = number;
        (*head_ptr) = tmp;
    } else {
        for (int i = 0; i < index - 2; i++) {
        current = current->next;
        }
        Node* tmp = new Node;
        tmp->next = current->next;
        tmp->field = number;
        current->next = tmp;
    }
}


auto new_list(int n) {
    Node *head_ptr = nullptr;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        add_node(&head_ptr, num);
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


int main() {
    int n = 0;
    int number = 0;
    int value = 0;
    Node *head = nullptr;


    cin >> n;


    Node *l = new_list(n);


    cout << "Make new list\n";
    print_list(&l);


    cout << "Append your element to the end of the list\n";
    cout << "Enter number" << endl;
    cin >> number;
    add_node(&l, number);
    print_list(&l);


    cout << "Delete your element from the end of the list\n";
    pop(&l);
    print_list(&l);


    cout << "Append your element on the i-th place\n";
    add_element(&l);
    print_list(&l);


    cout << "Delete element with your index\n";
    pop_element(&l);
    print_list(&l);


    cout << "Delete element by value\n";
    cin >> value;
    delete_by_value(&l, value);
    print_list(&l);


    cout << "Delete list" << endl;
    delete_list(&l);
    print_list(&l);


    return 0;
}
