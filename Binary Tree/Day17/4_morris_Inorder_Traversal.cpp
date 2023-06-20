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
void morrisTraversal(node *root, vector<int> &v)
{
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {

            v.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                v.push_back(curr->data);
                curr = curr->right;
            }
        }
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
    vector<int> v;
    morrisTraversal(root, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
// TIME COMPLEXITY: O(N)
// Reason: We are traversing N nodes and every node is visited exactly once
// SPACE COMPLEXITY:O(1)
// We are not using recursion