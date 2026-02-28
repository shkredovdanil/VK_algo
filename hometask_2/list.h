#include <iostream>

struct Node
{
    int x{};
    Node *next{};
    Node(int x) : x{x} {}
};

struct List
{
    Node *head{};
    int len{};
};

Node *
new_node(int x)
{
    Node *tmp = new Node{x};

    return tmp;
}

void
free_list(List &list)
{
    Node *node = list.head;
    for (int i = 0; i < list.len; i++) {
        Node *tmp = node->next;
        delete node;
        node = tmp;
    }

    list.head = nullptr;
    list.len = 0;
}

void
get_list(List &list, int arr[], int n)
{
    Node *tail{};
    for (int i = 0; i < n; i++) {
        int x{arr[i]};
        if (!list.head) {
            list.head = new_node(x);
            tail = list.head;
        } else {
            tail->next = new_node(x);
            tail = tail->next;
        }

        list.len++;
    }
}

void
print_list(List &list)
{
    Node *tmp = list.head;
    while (tmp) {
        std::cout << tmp->x << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}
