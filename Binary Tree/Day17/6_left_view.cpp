// left view
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
void leftview(node *root, vector<int> &v, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    if (v.size() == lvl)
    {
        v.push_back(root->data);
    }
    leftview(root->left, v, lvl + 1);
    leftview(root->right, v, lvl + 1);
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
    int lvl = 0;
    leftview(root, v, lvl);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY:O(H) height of the tree