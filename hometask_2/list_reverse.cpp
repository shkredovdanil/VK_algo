#include <iostream>
#include <print>
#include "list.h"

struct List;
struct Node;

void free_list(List &list);
void get_list(List &list, int n);
void get_list(List &list, int arr[], int n);
void print_list(List &list);

void
reverse(List &list)
{
    Node *head = list.head;
    Node *prev = nullptr;

    while (head) {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    list.head = prev;
}

int
main()
{
    {
        std::println("Test 1: [1, 2, 3, 4, 5]. Expected: [5, 4, 3, 2, 1]");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        reverse(list);

        print_list(list);
    }
    {
        std::println("Test 2: [0]. Expected: [0]");
        int x[]{0};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        reverse(list);

        print_list(list);
    }
    {
        std::println("Test 3: []. Expected: []");
        int x[1]{0};
        List list;

        get_list(list, x, 0);
        reverse(list);

        print_list(list);
    }
}
