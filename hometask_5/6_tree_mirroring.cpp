struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void
mirrorTree(Node *root)
{
    if (root == nullptr) {
        return;
    }

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);

    mirrorTree(root->right);
}

/*
Сложность - O(n). Проход по всем узлам дерева и swap поддеревьев
*/
