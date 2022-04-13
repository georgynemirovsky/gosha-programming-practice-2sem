#include <iostream>

using namespace std;


struct Node
{
    int field;
    Node* next;
};


struct List
{
    Node* head;

    List ()
    {
        head = nullptr;
    }


    void add_node(int value)
    {
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
    }


    auto new_list(int n)
    {
        head = nullptr;
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;
            add_node(num);
        }
        return head;
    }


    int find_loop()
    {
        Node *current = head;
        Node *tmp = head->next;
        int len_prev = 0;
        if (tmp == nullptr)
        {
            return -1;
        } else
        {
            while (tmp != nullptr)
            {
                int len_now = 0;
                current = head;
                while (current != tmp)
                {
                    len_now++;
                    current = current->next;
                }
                if (len_now < len_prev)
                {
                    return (len_now + 1);
                } else
                {
                    len_prev = len_now;
                }
                tmp = tmp->next;
            }
            return -1;
        }
    }


    void loop_push(int index, int value)
    {
        Node* current = head;
        Node* start_loop = current;
        int i = 0;
        while (current->next != nullptr)
        {
            i++;
            if (i == index)
            {
                start_loop = current;
            }
            current = current->next;
        }
        Node* tmp = new Node;
        current->next = tmp;
        tmp->field = value;
        tmp->next = start_loop;
    }


    void delete_list()
    {
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


int main()
{
    int n = 0;
    int index = 0;
    int value = 0;
    cin >> n;
    List l;
    l.new_list(n);
    cout << l.find_loop() << endl;
    cin >> index >> value;
    l.loop_push(index, value);
    cout << l.find_loop() << endl;
    l.delete_list();
    return 0;
}
