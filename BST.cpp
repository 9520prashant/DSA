#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
     int data;
     Node*left;
     Node*right;

     Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
     }
};
void LevelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL); 

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}
Node* insertIntoBSt(Node*root,int data)
{
    // base case
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        // insert element into right part
        root->right=insertIntoBSt(root->right,data);
    }
    else{
        // insert element into left part
        root->left=insertIntoBSt(root->left,data);
    }
    return root;

}
void inorder(Node*root){
    if(root==NULL){
        return ;
    }
     inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void takeInput(Node* &root){

    int data;
    cin>>data;

    while (data!=-1)
    {
       root= insertIntoBSt(root,data);
        cin>>data;
    }
    
}
// Search a Node in BST Recursively
bool SearchInBST(Node*root,int x){

    //
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    // check if x < root->data then We have to search in left Tree
    if(x < root->data){
        return SearchInBST(root->left,x);
    }
    // else We have to search in left Tree
    else{
        return SearchInBST(root->right,x);
    }
}
// Search a Node in BST Iteratively
bool searchInBST(BinaryTreeNode<int> *root, int x) {
   
    BinaryTreeNode<int>*temp=root;
    
    while(temp!=NULL){
        if(x==temp->data){
            return true;
        }
        if(x < temp->data){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        
    }
    return false;
}
// Minimum Value in BST
int MinimumInBST(Node*root){
    Node*temp=root;

    while (temp->left)// Why? Left -> Because In BST Minimum value is Always Store at left side
    {
        temp=temp->left;
    }
    return temp->data;
}

// Maximum Value in BST
int MaximumInBST(Node*root){
    Node*temp=root;

    while (temp->right)//Why? right -> Because In BST Maximum value is Always Store at right side
    {
        temp=temp->right;
    }
    return temp->data;
}
int main()
{
    Node*root=NULL;
    cout<<"Enter Data to Create BST"<<endl;//10 21 8 27 7 5 4 3 -1
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    LevelOrderTraversal(root);
    cout<<"Printing Inorder"<<endl;
    inorder(root);
    cout<<"\nPrinting Preorder"<<endl;
    preorder(root);
    cout<<"\nPrinting Postorder"<<endl;
    postorder(root);
    cout<<endl<<SearchInBST(root,0)<<endl;
    cout<<"Minimum Value is:"<<MinimumInBST(root)<<endl;
    cout<<"maxiimum Value is:"<<MaximumInBST(root)<<endl;
    return 0;
}