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
bool path(node *root, vector<int> &v, int x)
{
    if (root == NULL)
    {
        return false;
    }
    v.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }

    bool l = path(root->left, v, x);
    bool r = path(root->right, v, x);
    if (l == 1 || r == 1)
    {
        return true;
    }
    v.pop_back();
    return false;
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
    int x = 70;
    bool ispresent = path(root, v, x);
    if (ispresent)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        cout << "No path exist";
    }
    return 0;
}