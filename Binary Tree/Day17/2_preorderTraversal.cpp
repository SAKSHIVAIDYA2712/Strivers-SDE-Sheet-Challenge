// preorder traversal
// root left right
// pre-->root at first

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};
void preordertraversal(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    preordertraversal(root->left, v);
    preordertraversal(root->right, v);
}
int main()
{
    node *root = new node(10);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);
    vector<int> v;
    preordertraversal(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}