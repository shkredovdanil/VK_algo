#include <iostream>
#include <print>
#include "list.h"

struct List;
struct Node;

void free_list(List &list);
void get_list(List &list, int arr[], int n);
void print_list(List &list);

List
merge(List &l1, List &l2)
{
    Node *head = new_node(0);
    Node *h1 = l1.head, *h2 = l2.head;

    List res;
    res.head = head;
    res.len = l1.len + l2.len;

    while (h1 && h2) {
        if (h1->x < h2->x) {
            head->next = h1;
            head = head->next;
            h1 = h1->next;
        } else {
            head->next = h2;
            head = head->next;
            h2 = h2->next;
        }
    }

    while (h1) {
        head->next = h1;
        head = head->next;
        h1 = h1->next;
    }

    while (h2) {
        head->next = h2;
        head = head->next;
        h2 = h2->next;
    }

    Node *tmp = res.head;
    res.head = res.head->next;
    delete tmp;

    return res;
}

int
main()
{
    {
        std::println("Test 1: [1, 2, 3], [2, 3]. Expected: [1, 2, 2, 3, 3]");
        int x[]{1, 2, 3};
        List list1;
        get_list(list1, x, sizeof(x) / sizeof(*x));

        int y[]{2, 3};
        List list2;
        get_list(list2, y, sizeof(y) / sizeof(*y));
        List res = merge(list1, list2);

        print_list(res);
    }
    {
        std::println("Test 2: [1, 2, 3], []. Expected: [1, 2, 3]");
        int x[]{1, 2, 3};
        List list1;
        get_list(list1, x, sizeof(x) / sizeof(*x));

        int y[1]{};
        List list2;
        get_list(list2, y, 0);
        List res = merge(list1, list2);

        print_list(res);
    }
    {
        std::println("Test 3: [1, 2, 3], [4, 5, 6]. Expected: [1, 2, 3, 4, 5, 6]");
        int x[]{1, 2, 3};
        List list1;
        get_list(list1, x, sizeof(x) / sizeof(*x));

        int y[]{4, 5, 6};
        List list2;
        get_list(list2, y, sizeof(y) / sizeof(*y));
        List res = merge(list1, list2);

        print_list(res);
    }
    {
        std::println("Test 4: [1, 3], [0, 2, 4]. Expected: [0, 1, 2, 3, 4]");
        int x[]{1, 3};
        List list1;
        get_list(list1, x, sizeof(x) / sizeof(*x));

        int y[]{0, 2, 4};
        List list2;
        get_list(list2, y, sizeof(y) / sizeof(*y));
        List res = merge(list1, list2);

        print_list(res);
    }
}
