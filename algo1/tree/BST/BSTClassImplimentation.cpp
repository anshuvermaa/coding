#include<iostream>
using namespace std;
template<typename T>
class BTNode{
    public:
    T data;
    BTNode * left;
    BTNode * right;

    BTNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;

    }
    ~BTNode(){
        delete left;
        delete right;
    }


};

class Pair{
    public:
    BTNode<int>* head;
    BTNode<int>* tail;

};

class BST{
 BTNode <int > * root;

 // printing the tree

void printTree(BTNode<int>* node){
   if( node==NULL){   /// base case
    return;
   }

   cout<< node->data<<": ";
   if( node->left!=NULL){
    cout<<"L"<< node->left->data;
   }

   if( node->right!=NULL){
    cout<<"R"<< node->right->data;
   }
   cout<<endl;
   printTree( node->left);
   printTree( node->right);
}

// has data
 bool hasData(BTNode<int>* node,int data){
    if(node==NULL){return false;}
    if(node->data==data){return true;}
    if(node->data>data){return hasData(node->left,data);}
    else{return hasData(node->right,data);}

 }

 // insertion of data
 BTNode<int>* insertData(BTNode<int>* node,int data){
  if(node==NULL){
    BTNode<int>* n = new BTNode<int>(data);
    return n;
    }
    if(node->data>=data){
        node->left=insertData(node->left,data);
    }else{
        node->right=insertData(node->right,data);
    }
    return node;

 }
 BTNode<int>* deleteData(BTNode<int>* node,int data){
    if(node==NULL)return NULL;
  
    if(node->data>data){
        node->left=deleteData(node->left,data);
 }else if(node->data>data){
    node->right=deleteData(node->right,data);
 }else if(node->data==data){
      if(node->left==NULL && node->right==NULL) {
        delete node;
        return NULL;
    }else if(node->left==NULL){
        BTNode <int > * temp=node->right;
        node->right=NULL;
        delete node;
        return temp;
   }else if(node->right==NULL){
    BTNode <int > * temp=node->left;
    node->left=NULL;
    delete node;
    return temp;
   }else{
    BTNode <int > * minNode=node->right;
    while(minNode->left!=NULL){
        minNode=minNode->left;
    }
    int rightMin=minNode->data;
    node->data=rightMin;
    node->right=deleteData(node->right,rightMin);
   }

 }
 return node;
 }

    Pair convertToLL(BTNode<int>* root){
        if(root==NULL){
            Pair ans;
            ans.head = NULL;
            ans.tail = NULL;
            return ans;
        }
         if(root->left == NULL && root->right==NULL){
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
         }else if(root->left!=NULL && root->right==NULL){
              Pair leftLL = convertToLL(root->left);
              leftLL.tail->right = root;
              Pair ans;
              ans.head = leftLL.head;
              ans.tail = root;
              return ans;
         }else if(root->left==NULL && root->right!=NULL){
             Pair rightLL = convertToLL(root->right);
             root->right = rightLL.head;
             Pair ans;
             ans.head = root;
             ans.tail = rightLL.tail;
             return ans;
         }else{
           Pair leftLL = convertToLL(root->left);
           Pair rightLL = convertToLL(root->right);
           leftLL.tail->right = root;
           root->right = rightLL.head;
           Pair ans;
           ans.head = leftLL.head;
           ans.tail = rightLL.tail;
           return ans;
         }
    }
     public:
       BST(){
        root = NULL;
       }
       ~BST(){
        delete root;
       }
       void deleteData(int data){
         root=deleteData(root,data);

       }
       void insertData(int data){
        root=insertData(root,data);
          

       }
       bool hasData(int data){
        return hasData(root,data);

       }
       void print(){
        return printTree(root);

       }
       BTNode<int>* converToLL(){
          Pair p=convertToLL(root);
          return p.head;

       }



}; 

int main(){
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);
    b.print();
     b.deleteData(10);
     cout<<"helo"<<endl;
    b.print();
    BTNode<int>* n=b.converToLL();
    BTNode<int>* temp=n;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }
    
    return 0; 
}