// single Traversal
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
void singleTraversal(node *root, vector<vector<int>> &v)
{
    if (root == NULL)
    {
        return;
    }
    v[0].push_back(root->data);
    singleTraversal(root->left, v);
    v[1].push_back(root->data);
    singleTraversal(root->right, v);
    v[2].push_back(root->data);
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
    vector<vector<int>> v(3);
    singleTraversal(root, v);
    cout << "preorder:";
    for (int i = 0; i < v[0].size(); i++)
    {
        cout << v[0][i] << " ";
    }
    cout << "inorder:";
    for (int i = 0; i < v[1].size(); i++)
    {
        cout << v[1][i] << " ";
    }
    cout << "postorder:"
         << " ";
    for (int i = 0; i < v[2].size(); i++)
    {
        cout << v[2][i] << " ";
    }
    return 0;
}