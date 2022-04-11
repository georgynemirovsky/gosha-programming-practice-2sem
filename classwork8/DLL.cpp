#include <iostream>

using namespace std;


struct Node {
    int field = 0;
    Node* prev;
    Node* next;
};


struct List {
  Node* head;
  Node* tail;


  List(int value) {
    head = new Node;
    head->next = nullptr;
    head->prev = nullptr;
    tail = head;
  }


  List() {
    head = nullptr;
    tail = head;
  }


  void append(int value) {
    Node* current = head;
    if (current == nullptr) {
        (head) = new Node;
        (head)->prev = nullptr;
        (head)->next = nullptr;
        (head)->field = value;
    } else {
        while (current->next != nullptr) {
            current = current->next;
        }
        Node *tmp = new Node;
        current->next = tmp;
        tmp->prev = current;
        tmp->next = nullptr;
        tmp->field = value;
    }
  }


  auto new_list(int n) {
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        append(num);
    }
}


  void print_list() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->field << " ";
        current = current->next;
    }
    cout << endl;
  }


  Node* delete_by_index(int index) {
      int i = 0;
      Node* current = head;
      if (index != 1) {
        while (i != index - 1) {
           i++;
           current = current->next;
        }
        if (current->next != nullptr) {
           Node* prev = current->prev;
           Node* next = current->next;
           prev->next = next;
           next->prev = prev;
           delete current;
           return current;
        } else {
            (current->prev)->next = nullptr;
            delete current;
            return current;
            }
      } else {
        head = current->next;
        head->prev = nullptr;
        delete current;
        return current;
      }
  }


  Node* delete_by_value(int value) {
    Node* current = head;
    if ((head->field) != value) {
        while (value != current->field) {
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* prev = current->prev;
            Node* next = current->next;
            prev->next = next;
            next->prev = prev;
            delete current;
            return current;
        } else {
            (current->prev)->next = nullptr;
            delete current;
            return current;
        }
    } else {
        head = current->next;
        head->prev = nullptr;
        delete current;
        return current;
    }
  }


  void add(int index, int value) {
      Node* current = head;
      if (index == 1) {
        Node* tmp = new Node;
        tmp->next = head;
        tmp->field = value;
        tmp->prev = nullptr;
        current->prev = tmp;
        head = tmp;
      } else {
        int i = 1;
        while (i < index - 1) {
            i++;
            current = current->next;
        }
        if (current->next != nullptr) {
            Node* tmp = new Node;
            Node* current1 = current->next;
            current->next = tmp;
            current1->prev = tmp;
            tmp->next = current1;
            tmp->prev = current;
            tmp->field = value;
        } else {
            Node* tmp = new Node;
            current->next = tmp;
            tmp->prev = current;
            tmp->next = nullptr;
            tmp->field = value;
        }
      }
  }


  void delete_list() {
    Node *current = (head);
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


int main() {
    int n = 0;
    int index = 0;
    int value = 0;

    cout << "Enter number of element\n";
    cin >> n;
    List A;
    A.new_list(n);

    cout << "This is new list\n";
    A.print_list();

    cout << "Index of the element witch you want delete\n";
    cin >> index;
    A.delete_by_index(index);
    A.print_list();

    cout << "Value of the element witch you want delete\n";
    cin >> value;
    A.delete_by_value(value);
    A.print_list();

    cout << "Enter index and value of element witch you want append\n";
    cin >> index >> value;
    A.add(index, value);
    A.print_list();

    cout << "Delete list\n";
    A.delete_list();
    return 0;
}
