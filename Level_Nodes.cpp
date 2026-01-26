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
Node * input()
{
   int val;
   cin>>val;
   Node*root;
   if(val==-1)root=NULL;
   else root=new Node(val);
   queue<Node*>q;
   if(root) q.push(root);
   while (!q.empty())
   {
    /* code */
    Node*f=q.front();
    q.pop();
    int l,r;
    cin>>l>>r;
    Node* myl,*myr;
    if(l==-1)myl=NULL;
    else myl=new Node(l);
    if (r==-1) myr=NULL;
    else myr = new Node(r);
    f->left=myl;
    f->right=myr;
    if(f->left) q.push(f->left);
    if(f->right)q.push(f->right);
   }
   return root;
}
int  hight (Node*root)
{
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL) return 0;

   
   int l= hight(root->left);
   int r= hight(root->right);
    return max(l,r) +1;
}
void opration(Node*root, int co,int x)
{
    if (root==NULL)return;
    if(co==x)
    {
        cout<<root->val<<" ";
        return;
    }
    opration (root->left,co+1,x);
    opration(root->right,co+1,x);
}

 int main()

{
 Node* root=input();
 int x;
 cin>>x;
 int hig= hight(root);
 

    
    if (x > hig || x < 0) {
        cout << "Invalid" << endl;
    } else {
        opration(root, 0, x);
        cout << endl;
    }


    return 0;
}