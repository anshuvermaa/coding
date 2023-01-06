#include<bits/stdc++.h>
using namespace std;


class BSTNode{
    public:
    int data;
    BSTNode * left;
    BSTNode * right;
    BSTNode(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }

};


// searchNode and returning it method 1

BSTNode * searchNode(BSTNode * root,int ele){
    if(root==NULL) return NULL;
    if(root->data==ele) return root;
    if(root->data>ele) return searchNode(root->left,ele);
    else if(root->data<ele) return searchNode(root->right,ele);
    return NULL;
}
 // method iterative one 

 
 BSTNode * searchNodeByItration(BSTNode * root,int ele){
    while(root!=NULL){
        if(root->data==ele) {return root;}
        if(root->data < ele){
            root = root->right;
        }else if(root->data > ele){
            root=root->left;
        }
    }
    return NULL;
}


// find the min  value in bst

BSTNode * minValue(BSTNode * root){
    if(root==NULL) return NULL;
    if(root->left==NULL){
        return root;
        }
       return minValue(root->left);
}


// range sum in BST

int rangeSum(BSTNode * root,int L,int R){
    if(root==NULL) return 0;
    int sum=0;
    if (root->data<=R && root->data>=L){
        sum+=root->data;
    }
    if(root->data>R){
        sum+=rangeSum(root->left,L,R);

    }else if(root->data<L){
        sum+=rangeSum(root->right, L,R);
    }else{
        sum+=rangeSum(root->left, L,R)+rangeSum(root->right, L,R);
    }
    return sum;
    


}

// validating BST

bool helper(BSTNode * root,long long min=-1000000000,long long max=1000000000){
    bool left=helper(root->left,min,root->data);
    bool right=helper(root->right,root->data,max);
    if(left && right && root->data>min && root->data<max){
        return true;
}else {
    return false;
}
}
bool isValidBST(BSTNode *root){
    return helper(root);
}


// conver sorted array to bst
// note .the inorder trivaersal of BST is a sorted array

BSTNode * BSTBySortedArray(vector <int > &v){
    int n=v.size() -1;
    return helperSortedArray(v,0,n);
}
BSTNode * helperSortedArray(vector <int > &v,int s,int e){
    if(s>e) return NULL;
    int mid=(s+e)/2;
    int data=v[mid];
    BSTNode * root=new BSTNode(data);
    root->left=helperSortedArray(v,s,mid-1);
    root->right=helperSortedArray(v,mid+1,e);
    return root;
}


BSTNode * takeInput(){
    cout<<"enter the root data node";
    int value;
    cin >> value;
    cout<<endl;
    BSTNode * root=new BSTNode(value);
    queue<BSTNode*> q;
    q.push(root);
while(!q.empty()){    
    BSTNode * f=q.front();
    cout<<"enter the number of child of:"<<f->data<<" ";
    q.pop();
    int n;
    cin>>n;
    cout<<endl;
    if(n==2 || n==0){for(int i=0; i<n; i++){
        if(i==0){
            cout<<"enter the left child of "<<f->data<<" ";
            int value;
            cin >> value;
            cout<<endl;
            BSTNode * leftNode = new BSTNode(value);
            f->left=leftNode;
            q.push(leftNode);
       }
            if(i==1){
            cout<<"enter the right child of "<<f->data<<" ";
            int value;
            cin >> value;
            cout<<endl;
            BSTNode * rightNode = new BSTNode(value);
            f->right=rightNode;
            q.push(rightNode);
       }

       
    }}else if(n==1){
        cout<<"left child -> 1 for right -> 2 ";
        switch(n){
            case 1:
               { cout<<"enter the left child of "<<f->data<<" ";
                int value;
                cin >> value;
                cout<<endl;
                BSTNode * leftNode = new BSTNode(value);
                f->left=leftNode;
                q.push(leftNode);}
            case 2:
              {  cout<<"enter the right child of "<<f->data<<" ";
                int value;
                cin >> value;
                cout<<endl;
                BSTNode * rightNode = new BSTNode(value);
               f->right=rightNode;
               q.push(rightNode);}
        }

    }else{
        cout<<"value of child not exceed than 2";
    }

}
return root;

}



BSTNode * insert(BSTNode *root, int ele){
    if (root==NULL){
        BSTNode * n = new BSTNode(ele);
        return n;
    }
    if(ele < root->data){
        root->left = insert(root->left, ele);
    }else{
          root->right = insert(root->right, ele);
    }
    return root;
}

void printTreeLevel(BSTNode * root){
    cout<<"root:"<<root->data<<endl;
    queue<BSTNode*> q;
    q.push(root);
while(!q.empty()){    
    BSTNode * f=q.front();
    if(f->left){
        cout<<"L:"<<f->left->data<<" ";
        q.push(f->left);
    }
    if(f->right){
        cout<<"R:"<<f->right->data<<" ";
        q.push(f->right);
    }
    q.pop();
    cout<<endl;

  

}
}



int main(){
    BSTNode * root =new BSTNode(30);
    for(int i=0;i<6;i++){
        int data;
        cout<<"enter the data: ";
        cin >> data;
        root=insert(root,data);
        cout<<endl;
    }
    printTreeLevel(root);
    BSTNode * n=searchNode(root,10);
    cout<<"data"<<n->data<<endl;
    n=searchNodeByItration(root,10);
    cout<<"data By itration"<<n->data<<endl;
    n=minValue(root);
    cout<<"min Value"<<n->data<<endl;
    cout<<rangeSum(root,10,15)<<endl;
    return 0;
}