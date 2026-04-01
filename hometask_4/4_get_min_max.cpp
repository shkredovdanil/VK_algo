#include <optional>

struct Node
{
    int key_{};
    Node *left_{}, *right_{};

    Node() = default;
    Node(int key, Node *left = nullptr, Node *right = nullptr) : key_{key}, left_{left}, right_{right} {}
};

/*
h = log(n) - высота дерева. Два раза спускаемся по дереву => O(log(n))
*/

int
get_min(Node *root)
{
    if (!root->left_) {
        return root->key_;
    }

    return get_min(root->left_);
}

int
get_max(Node *root)
{
    if (!root->right_) {
        return root->key_;
    }

    return get_max(root->right_);
}

std::optional<int>
solution(Node *root)
{
    if (!root) {
        return std::nullopt;
    }

    return get_max(root) * get_min(root);
}
