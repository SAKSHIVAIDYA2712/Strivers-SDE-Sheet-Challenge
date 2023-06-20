// Inorder Traversal
// left root right
// Trick to remember: in means root should be present at middle

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void inordertraversal(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inordertraversal(root->left, v);
    v.push_back(root->data);
    inordertraversal(root->right, v);
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
    inordertraversal(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}