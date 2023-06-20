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
void verticalTraversal(node *root, queue<pair<node *, pair<int, int>>> q,
                       map<int, pair<int, vector<int>>> mpp)
{
    vector<int> ans;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto it = q.front();
            node *temp = it.first;
            q.pop();
            int ver = it.second.first;
            int lvl = it.second.second;
            mpp[ver].second.push_back(temp->data);
            if (temp->left != NULL)
            {
                q.push({temp->left, {ver - 1, lvl + 1}});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, {ver + 1, lvl + 1}});
            }
        }
    }
    for (auto p : mpp)
    {
        for (auto q : p.second.second)
        {
            ans.push_back(q);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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
    queue<pair<node *, pair<int, int>>> q;
    map<int, pair<int, vector<int>>> mpp;
    q.push({root, {0, 0}});
    verticalTraversal(root, q, mpp);
    return 0;
}