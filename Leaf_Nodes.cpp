#include <bits/stdc++.h>

using namespace std;
class Node

{

public:
    int val;

    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input()
{
    int valu;
    cin >> valu;
    Node *root;
    if (valu == -1)
        root = NULL;
    else
        root = new Node(valu);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myl, *myr;
        if (l == -1)
            myl = NULL;
        else
            myl = new Node(l);
        if (r == -1)
            myr = NULL;
        else
            myr = new Node(r);
        f->left = myl;
        f->right = myr;
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
}
void sum(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
        return;
    }

    sum(root->left, v);
    sum(root->right, v);
}

int main()

{
    Node *root = input();
    vector<int> v;
    sum(root, v);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int val : v)
    {
        cout << val << " ";
    }

    return 0;
}