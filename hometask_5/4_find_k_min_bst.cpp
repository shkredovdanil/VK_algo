struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *
findKthSmallest(Node *root, int &k)
{
    if (root == nullptr) {
        return nullptr;
    }

    Node *left = findKthSmallest(root->left, k);
    if (left != nullptr) {
        return left;
    }

    k--;
    if (k == 0) {
        return root;
    }

    return findKthSmallest(root->right, k);
}
