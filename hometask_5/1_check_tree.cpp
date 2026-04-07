#include <queue>

struct Node
{
    int key_{};
    Node *left_{}, *right_{};
    Node(Node *left = nullptr, Node *right = nullptr, int key = 0) : key_(key), left_(left), right_(right) {}
};

bool
is_complete_tree(Node *root)
{
    if (!root) {
        return true;
    }

    std::queue<Node *> nodes;
    nodes.push(root);

    bool null_obj{false};
    while (!nodes.empty()) {
        Node *tmp = nodes.front();
        nodes.pop();

        if (!tmp) {
            null_obj = true;
        } else {
            if (null_obj) {
                return false;
            }
            nodes.push(tmp->left_);
            nodes.push(tmp->right_);
        }
    }
    return true;
}


/*
Производим обход в ширину, закидывая указатели в очередь
Если на предыдущем шаге натыкаемся на null pointer => дерево закончилось.
*/