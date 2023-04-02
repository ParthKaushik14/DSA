#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *insertIntoBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        // roght part m insert
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        // 0child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child present
        if (root->left != NULL && root->right != NULL)
        {
            //int mini = minVal(root->right)->data;
           // root->data = mini; 
            //root->right = deleteFromBST(root->right , mini);
            return root; 
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to creat BST"
         << "\n";
    takeInput(root);
    cout << "printing the BST"
         << "\n";
    levelOrderTraversal(root);

    return 0;
}