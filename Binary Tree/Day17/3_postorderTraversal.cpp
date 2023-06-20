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
void postordertraversal(node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    postordertraversal(root->left, v);
    postordertraversal(root->right, v);
    v.push_back(root->data);
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
    postordertraversal(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
// TIME COMPLEXITY: O(N)
// Reason: We are traversing N nodes and every node is visited exactly once
// SPACE COMPLEXITY:O(N)
// Reason:space is needed for Recursion stack space.