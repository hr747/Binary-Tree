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
Node* input()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1)
    root=NULL;
    else
    root=new Node(val);
    queue<Node*>q;
    if(root)
    q.push(root);
    while (!q.empty())
    {
        /* code */
        Node* f=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node*myl,*myr;
        if(l==-1)
        myl=NULL;
        else
        myl=new Node(l);
        if(r==-1)
        myr=NULL;
        else
        myr=new Node(r);
        f->left=myl;
        f->right=myr;
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);


    }
    return root;

}
void lavel(Node*root)
{
    if(root==NULL)
    {
        cout<<"empty";
        return;
    }
    int count =0;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        /* code */
        Node*f=q.front();
        q.pop();
        cout<<f->val<<" ";
        count++;
        if(f->left)
        q.push(f->left);
        if(f->right)
        q.push(f->right);

    }
    // count kora hoise 
//     cout<<endl; 
//    cout<< count; 
}

 int main()

{
    Node*root=input();
    lavel(root);

    return 0;
}