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
void printLeft(Node* root) {
    if (root==NULL) return;
    
    
    if (root->left) printLeft(root->left);
    else if (root->right) printLeft(root->right);
    
    
    if (root->left || root->right) {
        cout << root->val << " ";
    } else {
       
        cout << root->val << " ";
    }
}
void printRight(Node* root) {
    if (root==NULL) return;
    
    
    if (root->left || root->right) {
        cout << root->val << " ";
    } else {
        cout << root->val << " ";
        return; 
    }

    if (root->right) printRight(root->right);
    else if (root->left) printRight(root->left);
}


 int main()

{
 Node* root=input();
 if (root==NULL) return 0;

    
    if (root->left) {
        printLeft(root->left);
    }

   
    cout << root->val << " ";

    
    if (root->right) {
        printRight(root->right);
    }
 


    return 0;
}