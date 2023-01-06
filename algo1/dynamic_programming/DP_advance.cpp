#include<bits/stdc++.h>
using namespace std;
// find the longest subsequence of strings
// by recursion

int lcs(string s1,int i,string s2,int j){
    if(s1.length()==i||s2.length()==j) return 0;
    if(s1[i]==s2[j]) return 1+lcs(s1,i+1,s2,j+1);
    else{
        int op1,op2;
        op1=op2=0;
        op1=lcs(s1,i+1,s2,j);
        op2=lcs(s1,i,s2,j+1);
       int ans= max(op1,op2);
        return ans;
    }
}
// by dynamic programing

int lcs1(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

// given two strings word1 and word2 return min no. operations need to convert word1 to word2
//  you have following three operations permited on a word
// insert a character, delete a character, replace a character

// recursive approach

int MinD1(string s1,int m,string s2,int n){
    if(m==0) return n;  // inser whole s1
    else if(n==0) return m;  // delete whole s1
    else if(s1[m-1]==s2[n-1]) return MinD1(s1,m-1,s2,n-1);
 else{   int insert=MinD1(s1,m,s2,n-1);
    int del=MinD1(s1,m-1,s2,n);
    int replace=MinD1(s1,m-1,s2,n-1);
    return 1+min(insert,min(del,replace));
}
}

// that  problem with dp
int MinD2(string s1,string s2){
    int m=s1.size();
    int n=s2.size();

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                   int insert=dp[i][j-1];
                   int del=dp[i-1][j];
                   int replace=dp[i-1][j-1];
                 dp[i][j]= 1+min(insert,min(del,replace));
            }
        }
    }
    return dp[m][n];
}
// most imp problem 
// knapsack - pick the items so that u get the max profit weight or no. of items u can pic is fixed
// recursiv approach

int knapsack(int n,int w,vector<int>&itmw, vector<int>&price){
    if(n==0|| w<=0){
        return 0;
    }
    if(itmw[n-1]>w){
        return knapsack(n-1,w,itmw,price);
    }
    else{
        int ans1=0;
        int ans2=0;
        ans1=price[n-1]+knapsack(n-1,w-itmw[n-1],itmw,price);
        ans2=0+knapsack(n-1,w,itmw,price);
        return max(ans1,ans2);
    }
}

// solution by DP
int knapsack(int w,vector<int>&itmw, vector<int>&price){
    int n=price.size();
    int dp[n+1][w+1];



    return dp[n][w];
}



int main(){
    string s1="horse";
    string s2="ros";
    cout<<"lcs is by DP        "<<lcs1(s1,s2)<<endl;
    cout<<"lcs is by recursion "<<lcs(s1,0,s2,0)<<endl;
    cout<<"min distance by DP  "<<MinD2(s1,s2)<<endl;
    cout<<"min is by recursion "<<MinD1(s1,s1.size(),s2,s2.size())<<endl;
    vector<int> v1={4,3,5,6};
    vector<int> v2={25,10,20,60};
    int w=10;
    
    cout<<"max profit is by recursion "<<knapsack(v1.size(),w,v1,v2)<<endl;
    
    return 0;
}