// Bottom view
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
void bottomview(node *root)
{
    queue<pair<node *, int>> q;
    q.push({root, 0});
    map<int, int> mpp;
    vector<int> v;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int vl = it.second;
        node *node = it.first;
        mpp[vl] = node->data;
        if (node->left != NULL)
        {
            q.push({node->left, vl - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, vl + 1});
        }
    }

    for (auto it : mpp)
    {
        v.push_back(it.second);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
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
    bottomview(root);
    return 0;
}