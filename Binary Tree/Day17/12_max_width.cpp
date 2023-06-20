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
void maxwidth(node *root, queue<pair<node *, int>> q)
{
    int width = 0;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        int first = 0;
        int last = 0;
        for (int i = 0; i < n; i++)
        {

            auto it = q.front();
            int ver = it.second;
            node *temp = it.first;
            q.pop();
            if (i == 0)
            {
                first = ver;
            }
            if (i == n - 1)
            {
                last = ver;
            }
            if (temp->left != NULL)
            {
                q.push({temp->left, 2 * i + 1});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, 2 * i + 2});
            }
        }
        width = max(width, last - first + 1);
    }
    cout << width;
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
    queue<pair<node *, int>> q;
    maxwidth(root, q);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

// TC:o(N)
// SC:O(N)//becoz of queue DS