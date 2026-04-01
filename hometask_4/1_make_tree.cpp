#include <vector>
#include <memory>
#include <utility>

struct Node
{
    int key_{};
    std::unique_ptr<Node> left_{}, right_{};

    Node() = default;
    Node(int key, Node *left = nullptr, Node *right = nullptr)
        : key_{key}, left_{std::move(left)}, right_{std::move(right)}
    {
    }
};

/*
    Родитель хранит два указателя на сыновей и свой ключ
*/

std::unique_ptr<Node>
tree_restore(const std::vector<std::pair<bool, int>> &arr, int i = 0)
{
    if (i >= arr.size() || !arr[i].first) {
        return nullptr;
    }

    std::unique_ptr<Node> node = std::make_unique<Node>();
    node->key_ = arr[i].second;
    node->left_ = std::move(tree_restore(arr, i * 2 + 1));
    node->right_ = std::move(tree_restore(arr, i * 2 + 2));

    return node;
}
