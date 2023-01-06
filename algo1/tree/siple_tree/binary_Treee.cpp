#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BTNode{
    public:
    T data; 
    BTNode* left;
    BTNode* right;
    BTNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BTNode(){
        delete left;
        delete right;
    }

};


// for counting the modes present in the binary tree
int countNodes(BTNode<int>* root){
    if(root==NULL) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

// max dept of a binary tree node


int maxDepth(BTNode<int>* root){
    if(root==NULL) return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;

}

// check if given bianry tree is symetric or not


bool helper(BTNode<int>* leftTree, BTNode<int>* rightTree){
    if(leftTree!=NULL && rightTree==NULL) return false;
    if(leftTree==NULL && rightTree!=NULL) return false;
    if(leftTree->data =! rightTree->data) return false;
    if(leftTree==NULL && rightTree==NULL) return true;
    return helper(leftTree->left,rightTree->right) && helper(leftTree->right,rightTree->right);
}

bool isSymmetric(BTNode<int>* root){
    if(root==NULL) return true;
    return helper(root->left,root->right);
   
}


// checking if a perticular node exist or not

bool findNode(BTNode<int>* root,int x){
    if(root==NULL) return false;
    if(root->data==x) {
        return true;}
    bool left=findNode(root->left,x);
    bool right=findNode(root->right,x);

    return left || right ;

}

// finding the minimun value in binary tree 

int minValue(BTNode<int>* root){
    if (root==NULL) return 0;
    int ans=root->data;
    int leftMin=minValue(root->left);
    int rightMin=minValue(root->right);
    return min(root->data,min(leftMin,rightMin));
}

// finding the maximun value in binary tree



int maxValue(BTNode<int>* root){
    if (root==NULL) return 0;
    int ans=root->data;
    int leftMin=maxValue(root->left);
    int rightMin=maxValue(root->right);
    return max(root->data,max(leftMin,rightMin));
}




// counting the leaf nodes in a binary tree

int countLeafNodes(BTNode<int>* root){
    if(root==NULL) return 0;
  if(root->left==NULL && root->right==NULL) return 1;
  
  return countLeafNodes(root->left)+countLeafNodes(root->right);
  
}

//2nd method: count

void countLeafNodesOther(BTNode<int>* root,int &ans){
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL){
        ans++;
        return;
    }
    countLeafNodesOther(root->left,ans);
    countLeafNodesOther(root->right,ans);
}



// diameter of the binary tree 
// diameter- maximum distance between two nodes 
// max height of left tree + max height of right tree





// making tree by inorder triversal and preorder triversal


BTNode<int>* takeInput(){
    int data;
    cout<<"Enter data:";
    cin>>data;
    BTNode<int>* root=new BTNode<int>(data);
    cout<<"Enter the children of root "<<data<<" "<<endl;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){

        if(i==0){
    BTNode<int>*leftNode=takeInput();
    root->left=leftNode;

        }else{

    BTNode<int>*rightNode=takeInput();
    root->right=rightNode;
        }
  
    }

    return root;
    
  }
  

// diameter of the tree

int getDiameter(BTNode<int>* root){
    if(root==NULL) return 0;
    int option1=maxDepth(root->left) +maxDepth(root->right);
    int option2=getDiameter(root->left);
    int option3=getDiameter(root->right);
    return max(option1,max(option2,option3));

}


// second method important

pair<int,int> heightDiameter(BTNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
    }
    pair<int,int> leftAns=heightDiameter(root->left);
    pair<int,int> rightAns=heightDiameter(root->right);

   int lh=leftAns.first;
   int ld=leftAns.second;

   int rh=rightAns.first;
   int rd=rightAns.second;
   int height=1+ max(lh,rh);
   int diameter=max(lh+rh,max(ld,rd));
   pair<int,int> p;
   p.first=height;
   p.second=diameter;

   return p;

}

int getDiameterByPair(BTNode<int>* root){
    if(root==NULL) return 0;
    int option1=maxDepth(root->left) +maxDepth(root->right);
    int option2=getDiameter(root->left);
    int option3=getDiameter(root->right);
    return max(option1,max(option2,option3));

}


BTNode<int>* takeInputLevelWise(){
    int data;
    cout<<"Enter root data:";
    cin>>data;
    BTNode<int>*root=new BTNode<int>(data);
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<int> *f=q.front();
        q.pop();
        cout<<"Enter the children of "<<f->data<<" ";
        int n;
        cin>>n;
     for(int i=0;i<n;i++){
        if(i==0){
            int childData;
            cout<<"Enter the left child of "<<f->data<<" ";
            cin>>childData;
            BTNode<int>* leftNode=new BTNode<int>(childData);
            f->left=leftNode;
            q.push(leftNode);
        }
        if(i==1){
         
            int childData;
            cout<<"Enter the right child of "<<f->data<<" ";
            cin>>childData;
            BTNode<int>* rightNode=new BTNode<int>(childData);
            f->right=rightNode;
            q.push(rightNode);
        }
        
     }
       
    }
    return root;

}

void takeInput1(BTNode<int>* &node) {
    string left, right;
    int data;
    cin >> data; // input for root node
    node = new BTNode<int>(data);

    cin >> left;
    if(left == "true") {
        takeInput1(node->left); // taking input for left subtree
    }

    cin >> right;
    if(right == "true") {
        takeInput1(node->right); // taking input for right subtree
    }
}

BTNode<int>* InputBinaryTree() {
   BTNode<int>*root;
    takeInput1(root);
    return root;
}

void printBTreeLevelWise(BTNode<int>* root){
    queue<BTNode<int>*> q;
    q.push(root);
    cout<<root->data<<endl;
    while(!q.empty()){
        BTNode<int> *f=q.front();
        q.pop();
        if(f->left!=NULL){
            q.push(f->left);
            cout<<f->left->data<<" ";
        }
          if(f->right!=NULL){
            q.push(f->right);
            cout<<f->right->data<<" ";
        }
        if(f->right!=NULL || f->left!=NULL){
        cout<<endl;

        }

    }



}

// preorder triversal node left right
void printBT(BTNode<int>* node){ 
    if(node==NULL) return;
    cout<<node->data<<" ";
    printBT(node->left);
    printBT(node->right);
   

}

// inorder triversal left node right

void printBTInOrder(BTNode<int>* root){
    if(root!=NULL) return;
    printBTInOrder(root->left);
    cout<<root->data;
    printBTInOrder(root->right);
}

bool getPath(BTNode<int>* root, int val, vector<int> &ans){
   if(root==NULL){
    return false;
   }
   ans.push_back(root->data);
   if(root->data == val){
    return true;
   }

   bool left = getPath(root->left, val, ans);
   bool right = getPath(root->right, val, ans);

   if(left || right){
    return true;
   }
   ans.pop_back();
   return false;

}
int main(){
    /*    
    BTNode<int>*root=new BTNode<int>(1);
    BTNode<int>*n1=new BTNode<int>(2);
    BTNode<int>*n2=new BTNode<int>(3);                               //now to make tree make connection of root to n1 and n2
    root->left=n1;
    root->right=n2;
    cout<<root->left->data;
*/

    // do above thongs to make cnnections or directly connect them 

 /*
    BTNode<int>*root=new BTNode<int>(1);
    root->left=new BTNode<int>(2);
    root->right=new BTNode<int>(3);
    printBT(root);



    */



   // taking input by recursion and



//    BTNode<int>*root=takeInput();
//    printBT(root);

//    BTNode<int>*root=takeInputLevelWise();
   BTNode<int>*root=InputBinaryTree();
   printBTreeLevelWise(root);

   cout<<"count nodes"<<countNodes(root)<<endl;
   cout<<"is symetric"<<isSymmetric(root)<<endl;
   cout<<"maxDEpt"<<maxDepth(root)<<endl;
   cout<<"findNode"<<findNode(root,1)<<endl;
   cout<<"minVlue"<<minValue(root)<<endl;
   cout<<"maxVlue"<<maxValue(root)<<endl;
   cout<<"leaf nodes"<<countLeafNodes(root)<<endl;
   int ans=0;
   countLeafNodesOther(root,ans);
   cout<<"leaf nodes other method"<<ans<<endl;

   cout<<"diameter is= "<<getDiameter(root)<<endl;
   cout<<"By pair diameter is= "<<getDiameterByPair(root)<<endl;

   vector<int> v;
   if(getPath(root,8,v )){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"->";
    }
   }else{
    cout<<"No path found because value 9 is not present"<<endl;
   }
   

    return 0;
}