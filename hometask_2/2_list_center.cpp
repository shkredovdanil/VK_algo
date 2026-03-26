#include <print>
#include "list.h"

struct List;
struct Node;

void free_list(List &list);
void get_list(List &list, int arr[], int n);
void print_list(List &list);

Node *
center_list(List &list)
{
    Node *slow = list.head;
    Node *fast = list.head;

    if (!slow->next || !slow->next->next) {
        return slow;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next) {
            fast = fast->next;
        }
    }

    return slow;
}

/*
    v_fast = 2 * v_slow => когда быстрый в конце, медленный в центре
*/

int
main()
{
    {
        std::println("Test 1: [1, 2, 3, 4, 5]. Expected: 3");
        int x[]{1, 2, 3, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        Node *center = center_list(list);

        std::println("{}", center->x);
        free_list(list);
    }
    {
        std::println("Test 2: [1, 4, 5]. Expected: 4");
        int x[]{1, 4, 5};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        Node *center = center_list(list);

        std::println("{}", center->x);
        free_list(list);
    }
    {
        std::println("Test 3: [1]. Expected: 1");
        int x[]{1};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        Node *center = center_list(list);

        std::println("{}", center->x);
        free_list(list);
    }
    {
        std::println("Test 4: [1, 4]. Expected: 1/4");
        int x[]{1, 4};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        Node *center = center_list(list);

        std::println("{}", center->x);
        free_list(list);
    }
    {
        std::println("Test 5: [1, 4, 2, 3]. Expected: 4/2");
        int x[]{1, 4, 2, 3};
        List list;

        get_list(list, x, sizeof(x) / sizeof(*x));
        Node *center = center_list(list);

        std::println("{}", center->x);
        free_list(list);
    }
}
