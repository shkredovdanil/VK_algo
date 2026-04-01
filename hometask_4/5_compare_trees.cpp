struct Node
{
    int key_{};
    Node *left_{}, *right_{};

    Node() = default;
    Node(int key, Node *left = nullptr, Node *right = nullptr) : key_{key}, left_{left}, right_{right} {}
};

/*
    обход в глубину. Сравнение по ключу и проверка выделения узлов на двух деревьях
*/

bool
solution(Node *root1, Node *root2)
{
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if (root1 == nullptr || root2 == nullptr || root1->key_ != root2->key_) {
        return false;
    }

    return solution(root1->left_, root2->left_) && solution(root1->right_, root2->right_);
}
