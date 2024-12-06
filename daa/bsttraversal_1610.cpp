#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *insert(Node *&root,int data)
{
      if(root==NULL)
      {
        
        return new Node(data);
      }
      if(root->data>data)
      {
        root->left=insert(root->left,data);
      }
      else if(root->data<data)
      {
        root->right=insert(root->right,data);
      }
      return root;
}
void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void preorderiter(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack <Node *> s;
    s.push(root);
    while(!s.empty())
    {
        Node *k=s.top();
       s.pop();
        cout<<k->data<<" ";
        if(k->right)
        {
            s.push(k->right);
        }
        if(k->left)
        {
            s.push(k->left);
        }  
    }
  
}
void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void postorderiter(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    stack<Node *> s1,s2;
    s1.push(root);
    Node *k=root;
    while(!s1.empty())

{
    k=s1.top();
    s1.pop();
    s2.push(k);
    if(k->left)
    {
        s1.push(k->left);
    }
    if(k->right)
    {
        s1.push(k->right);
    }

}
   while (!s2.empty())
   {
    k=s2.top();
    s2.pop();
    cout<<k->data<<" ";

   }
   

}
void inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
   
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
}
void inorderiter(Node *root)
{
    
    if(root==NULL)
    {
        return;
    }
    stack<Node *>s;
    Node *k=root;
    while(!s.empty()|| k!=NULL)
    {
        while(k!=NULL)
        {
            s.push(k);
            k=k->left;
        }
        k=s.top();
        s.pop();
        cout<<k->data<<" ";
        k=k->right;
    }

}
int main()
{
    ofstream fout;
    string line;
    fout.open("num.txt");
    while(fout)
    {
        getline(cin,line);
        if(line=="-1")
        {
             break;
        }
        fout<<stoi(line)<<endl;
    }
    fout.close();
    
    ifstream fin;
    fin.open("num.txt");
    Node *root=NULL;
    int value;
    while(fin>>value)
    {
        root=insert(root,value);
    }
    fin.close();
    cout<<"pre order recursive"<<endl;
    preorder(root);
    cout<<endl;
     cout<<"in order recursive"<<endl;
    inorder(root);
    cout<<endl;
     cout<<"post order recursive"<<endl;
    postorder(root);
    cout<<endl;
     cout<<"in order iterative"<<endl;
    inorderiter(root);
    cout<<endl;
    cout<<"pre order iterative"<<endl;
    preorderiter(root);
    cout<<endl;
    cout<<"post order iterative"<<endl;
    postorderiter(root);
    cout<<endl;
    return 0;


}