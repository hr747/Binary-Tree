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
    int valu;
    cin>>valu;
    Node*root;
    if(valu==-1)root=NULL;
    else root=new Node(valu);
    queue<Node*>q;
    if(root)q.push(root);
    while (!q.empty())
    {
        Node*f=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node*myl,*myr;
        if(l==-1)myl=NULL;
        else myl=new Node(l);
        if(r==-1)myr=NULL;
        else myr=new Node(r);
        f->left=myl;
        f->right=myr;
        if(f->left)q.push(f->left);
        if(f->right)q.push(f->right);
    }
    return root;

}
int  count (Node*root)
{
    if(root==NULL) return 0;
   
   int l= count(root->left);
   int r= count(root->right);
    return l+r+1;
}
int  max_hight (Node*root)
{
    if(root==NULL) return -1;
    
   
   int l= max_hight(root->left);
   int r= max_hight(root->right);
    return max(l,r) +1;
}


 int main()

{
Node* root=input();
if(root==NULL){cout<<"YES"<<endl; return 0;}

int co= count(root);
int hig=max_hight(root);

if (co == pow(2, hig + 1) - 1) cout<<"YES"<<endl;
else cout<<"NO"<<endl;

    return 0;
}