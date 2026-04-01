#include <vector>
#include <memory>
#include <vector>
#include <utility>

struct Node
{
    int key_{};
    Node *left_{}, *right_{};

    Node() = default;
    Node(int key, Node *left = nullptr, Node *right = nullptr) : key_{key}, left_{left}, right_{right} {}
};

/*
    обход в ширину. Делаем массив элементов каждого уровня (обход в ширину). Проверяем на палиндром
*/

bool
check_symmetry(Node *root)
{
    if (!root) {
        return true;
    }

    std::vector<Node *> q;
    q.push_back(root);
    while (q.size() > 0) {
        size_t size = q.size();
        std::vector<Node *> next;
        for (int i = 0; i < size; i++) {
            if (q.at(i) == nullptr && q.at(size - i - 1) == nullptr) {
                continue;
            } else if (q.at(i) != nullptr && q.at(size - i - 1) == nullptr) {
                return false;
            } else if (q.at(i) == nullptr && q.at(size - i - 1) != nullptr) {
                return false;
            } else if (q.at(i)->key_ != q.at(size - i - 1)->key_) {
                return false;
            }

            next.push_back(q.at(i)->left_);
            next.push_back(q.at(i)->right_);
        }

        q = next;
        next.clear();
    }

    return true;
}
