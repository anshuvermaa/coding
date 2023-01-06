#include<iostream>
using namespace std;



// reversing linkedList

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(left == right) return head;
        stack<int> s;
        int i = 1;
        ListNode* temp = head;
        while(i <= right)
        {
            if(i >= left) s.push(temp->val);
            temp = temp->next;
            ++i;
        }
        if(!s.empty())
        {
            temp = head;
            i = 1;
            while(i <= right)
            {
               if(i >= left)
               {
                  temp->val = s.top();
                  s.pop();
               }
               temp = temp->next;
               ++i;
            }
        }
        return head;
    }
};


// max dept solution

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        
    }
};

int main(){
    
    return 0;
}


 //Binary Tree Level Order Traversal

 class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root)
        {return vec;
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int count=0;
            int length=q.size();
            vector<int> inVal;
            while(count<length){
                TreeNode *temp=q.front();
                q.pop();
                inVal.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                count++;
                
            }
            res.push_back(inVal);
            
        }
        
        return res;
       }
};




//Binary Tree Right Side View


class Solution {
   
public:
    
     void dfs(TreeNode* node,int curLevel,vector<int> &vec){
        if(curLevel>= vec.size()){
            vec.push_back(node->val);
        }
        if(node->right)  dfs(node->right,curLevel+1,vec);
       if(node->left)  dfs(node->left,curLevel+1,vec);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        vector<int> vec;
        dfs(root,0,vec);
        return vec;
        
    }
};

