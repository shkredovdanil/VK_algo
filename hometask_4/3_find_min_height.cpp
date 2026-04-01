#include <cstddef>
#include <algorithm>

struct Node
{
    int key_{};
    Node *left_{}, *right_{};

    Node() = default;
    Node(int key, Node *left = nullptr, Node *right = nullptr) : key_{key}, left_{left}, right_{right} {}
};

/*
    обход в глубину
*/

size_t
get_min_height(Node *root)
{
    if (!root) {
        return 0;
    }

    return std::min(get_min_height(root->left_), get_min_height(root->right_)) + 1;
}
