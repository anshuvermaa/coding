#include<bits/stdc++.h>
using namespace std;
// generic tree-> A node can have as many children as it want 
template<typename T>
class TreeNode{
    public:
      T data;
      vector<TreeNode<T>*> children;
      TreeNode(T data){
          this->data=data;
      }
      ~TreeNode(){
          for(int i=0; i<children.size();i++){
              delete children[i];
          }

}

}; 

// take input iteratively in this we use loops
// 1. create the node 2. push 3. connect it to the node 

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter the root data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* f=q.front();
        q.pop();
        cout<<"Enter the number of children"<<f->data<<":"<<endl;
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
           int childData;
           cout<<"Enter the "<<i<<"child of "<<f->data<<":"<<endl;
           cin>>childData;
           TreeNode<int>* child = new TreeNode<int>(childData);
           q.push(child);
           f->children.push_back(child);
        }
        


    }
    return root;

}






/// take inpute by height of tree if u know recursion only if u can give right input other wise it is very deficult to give input

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Take data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter the number of childrens:"<<rootData<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}


//printint tree accourding to children
// first print child and all the children of it and so on

void printTree(TreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<": ";
for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";

}
cout<<"\n";
for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);

}

}

//printing tree level wise
void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){ 
        TreeNode<int>* f=q.front();
        q.pop();
        cout<<f->data<<":";
        for(int i=0;i<f->children.size();i++){
            cout<<f->children[i]->data<<",";

        }
        cout<<endl;
       for(int i=0;i<f->children.size();i++){
            q.push(f->children[i]);

        }
        
            }


}

// print tree preOrder triversal 
// NODE LEFT RIGHT
void preOrder(TreeNode<int>* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }

}



// print tree postOrder triversal 
//  RIGHT LEFT  NODE
void postOrder(TreeNode<int>* root){
    if(root==NULL) return;
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";

}



// function for counting the nodes

int countTreeNodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=countTreeNodes(root->children[i]);

    }
    return ans;
}


// function for height of the tree
int height(TreeNode<int>* root){
     if(root==NULL){   //edge case
        return 0;
    }
   int mx = 0;  //  maximum height
   for(int i=0;i<root->children.size();i++){
     int childHeight = height(root->children[i]);
     if(childHeight > mx){
        mx = childHeight;
     }
     mx = max(mx, height(root->children[i]));
   }
   return mx + 1;
}



// print all the nodes at level K in the tree

void printAtLevelK(TreeNode<int>* root,int k){
    if(root==NULL){return;}
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
       printAtLevelK(root->children[i],k-1);
    }

}


// Counting no. of leaf nodes

int countLeafNodes(TreeNode<int>* root){
    if(root->children.size()==0) return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=countLeafNodes(root->children[i]);
    }
    return ans;
}


// deleting the node and entire tree


// deleting by recursive function
void deleteRoot(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        deleteRoot(root->children[i]);
    }
   delete root;

}


// deleting root node by destructor





int main(){
TreeNode<int>* root = takeInputLevelWise();
 
    printTreeLevelWise(root);

    cout<<"COUNT of NODES is:"<<countTreeNodes(root)<<endl;
    cout<<"Height"<<height(root)<<endl;
    cout<<"preoder triversal:";
    preOrder(root);
    cout<<endl;
     cout<<"postOrder triversal:";
    postOrder(root);
    cout<<endl;
    printAtLevelK(root,2);
    cout<<endl;
    cout<<countLeafNodes(root)<<endl;
    // deleteRoot(root);
    delete root;


     cout<<"postOrder triversal:";



    
    return 0;
}