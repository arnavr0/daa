#include<iostream>
#include<vector>

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
Node *search(Node *root,int target)
{
   if(root==NULL)
   {
     return NULL;
   }
   if(root->data==target)
   {
       return root;
    }
    else if(root->data<target)
    {
   
  search(root->right,target);
    }
    else
    {
    search(root->left,target);
     }
}

void minele( vector<int> & arr,Node *root)
{
   
    if(root==NULL)
    {
        return ;
    }
   
    minele(arr,root->left);
    arr.push_back(root->data);
    minele(arr,root->right);
}
void countleaf(int &count, Node *root)
{

   
   
    if(root==NULL)
    {
      return;
     }
     if(root->left==NULL && root->right==NULL)
    {
       count++;
       
    }
   
    countleaf(count,root->left);
    countleaf(count,root->right);
}
int  maxheight( Node *root)
{

    if(root==NULL)
    {
        return 0;
    }
   
   return max(maxheight(root->left),maxheight(root->right))+1;
}
void kdistance(Node *root,int k)
{

    if(root==NULL|| k<0)
    {
        return ;
    }
    if(k==0){
      cout<<root->data<<" ";
      }
    kdistance(root->left,k-1);
    kdistance(root->right,k-1);
   
   
}


int main()
{
    Node *root=NULL;
   
    int n;
    cout<<"enter number of elements in tree";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
    int x;
    cout<<"enter value:";
    cin>>x;
       if(root==NULL)
       {
           root=insert(root,x);
       }
       else
       {
         insert(root,x);
       }
   }
    vector<int> c;
    minele(c,root);
    cout<<"minimum element of the tree is:"<<c[0];
    cout<<endl;

    int p=maxheight(root);
    cout<<"maximum height of tree:"<<p<<endl;
    int count=0;
    countleaf(count,root);
    cout<<"leaf node is:"<<count<<endl;
    int k;
    cout<<"enter distance:";
    cin>>k;
    int s;
    cout<<"enter node from where distance is to be find";
    cin>>s;
    Node *m=search(root,s);
   
    kdistance(m,k);
    cout<<endl;
   
   
    return 0;


}
