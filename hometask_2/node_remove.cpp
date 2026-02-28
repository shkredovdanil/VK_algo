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
remove_node(List &list, int target)
{
    Node *prev = new_node(0);
    prev->next = list.head;
    Node *head = list.head;
    list.head = prev;

    while (head && head->x != target) {
        prev = head;
        head = head->next;
    }

    if (head) {
        prev->next = head->next;
        delete head;
        list.len--;
    }

    Node *tmp = list.head;
    list.head = list.head->next;
    delete tmp;
}

int
main()
{
    {
        std::println("Test 1: [1, 2, 3, 4, 5], 3. Expected: [1,2,4,5]");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        remove_node(list, 3);

        print_list(list);
    }
    {
        std::println("Test 2: [1, 2, 3, 4, 5], 1. Expected: [2, 3, 4, 5]");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        remove_node(list, 1);

        print_list(list);
    }
    {
        std::println("Test 3: [1, 2, 3, 4, 5], 5. Expected: [1, 2, 3, 4]");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        remove_node(list, 5);

        print_list(list);
    }
    {
        std::println("Test 4: [1, 2, 3, 4, 5], 6. Expected: [1, 2, 3, 4, 5]");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        remove_node(list, 6);

        print_list(list);
    }
}
