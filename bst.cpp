#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // If the node has two children
        struct node *temp = minValueNode(root->right);
        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 38);
    root = insert(root, 14);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 90);
    root = insert(root, 45);
    root = insert(root, 70);
    root = insert(root, 60);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);
    cout << "Inorder traversal: ";
    inorder(root);
}
