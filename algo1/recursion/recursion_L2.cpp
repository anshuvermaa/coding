#include<bits/stdc++.h>
using namespace std;

// checking palindron
// save all positions using array
// storing all the positions of all the occurence of an element in an array
// printing all the indexes of array
// returning last index of element in array
// returning last index of element in array
// returning first index of element in array
// checking if elemennt is present in array
// sum of all elemennts of an array
// checking sorted array or not




// checking sorted array or not by recursion
bool isSortedArray(int arr[],int n){
    if(n==0 || n==1) return true;
   
    bool smallAns=isSortedArray(arr+1,n-1);
     if (arr[0]>arr[1])
    {
        return false;
    }
    
    return smallAns;
}




// sum of all elemennts of an array

long sumArray(int arr[],int n){
    if (n==0) return 0;
    return arr[n-1]+sumArray(arr,n-1);

// or  return arr[0]+sumArray(arr+1,n-1);
}

// sum by index

long sumArray1(int arr[],int n,int i){
    if (n==0) return 0;
return arr[i]+sumArray1(arr+i+1,n-1-i,0);
}

//2nd method

long sumArray2(int arr[],int n,int i){
    if (n==i) return 0;
return arr[i]+sumArray2(arr,n,i+1);
}


//checking if elemennt is present in array

bool checkElement(int arr[],int n,int ele){
 if(n==0) return false;
 bool smallAns=checkElement(arr+1,n-1,ele);
 if(arr[0]==ele) return true;

 return smallAns;
}



// returning first index of element in array

int firstIndex(int arr[],int n,int x,int i){
    if (i==n) return -1;
    if(arr[i]==x) return i;
    return firstIndex(arr,n,x,i+1);
}


// returning last index of element in array

int lastIndex1(int arr[],int n,int x,int i){
    if (i==n) return -1;
    int smallAns=lastIndex1(arr,n,x,i+1);
   if(smallAns==-1) { if(arr[i]==x) return i;
    else return smallAns;
    }else return smallAns;
}
// returning last index of element in array method 2

int lastIndex2(int arr[],int n,int x){
    if (n==0) return -1;
    if(arr[n-1]==x) return n-1;
    return lastIndex2(arr,n-1,x);

}


// printing all the indexes of array

void printAllIndexes(int arr[],int n,int x,int i){
    if(n==i) return;
    if(arr[i]==x) cout<<i<<" ";
    printAllIndexes(arr,n,x,i+1);
}



// storing all the positions of all the occurence of an element in an array   m1

void storeAllPositions(int arr[],int n,int x,int i,vector<int> &ans){
    if(i==n) return;
    if(arr[i]==x) {
        ans.push_back(i);
    }      
    storeAllPositions(arr,n,x,i+1,ans);

}


// save all positions using array

int saveAllPositionsUsingArray(int arr[],int n,int x,int i,int ans[],int j){
    if(i==n) return 0;
    if(arr[i]==x) {
        ans[j]=i;
      return 1+  saveAllPositionsUsingArray(arr,n,x,i+1,ans,j+1);
    }else return 0+saveAllPositionsUsingArray(arr,n,x,i+1,ans,j);
}


// checking palindron using recursion


bool checkPalindron(string s,int n,int i=0){
    if(i==n/2) return true;
    bool smallAns=checkPalindron(s,n,i+1);
    if(s[i]!=s[n-1-i]){ 
        return false;
    }else return smallAns;
}

 
int main(){

    int arr[9]={1,2,3,4,5,6,2,8,9};             //checking array sorted or not 
    cout<<isSortedArray(arr,9)<<"\n";
    cout<<sumArray(arr,9)<<"\n";                   // sum of array
    cout<<sumArray1(arr,9,3)<<"\n";               // sum by index m1
    cout<<sumArray2(arr,9,3)<<"\n";               // sum by index m2
    cout<<checkElement(arr,9,8)<<"\n";               // checking element in an array
    cout<<firstIndex(arr,9,8,0)<<"\n";               // returning first index of an  element in an array
    cout<<lastIndex1(arr,9,2,0)<<"\n";               // returning first index of an  element in an array
    cout<<lastIndex2(arr,9,2)<<"\n";               // returning first index of an  element in an array method 2 using only n
    printAllIndexes(arr,9,2,0);   cout<<"\n";            // returning first index of an  element in an array method 2 using only n
    vector<int> ans;
    storeAllPositions(arr,9,2,0,ans);                  //saving positions unsing vetor
    for (int i = 0; i < ans.size(); i++)
    {
       cout<< ans[i]<<" "; 
    }
    cout<< endl; 
    
    int ar[10];
   int count= saveAllPositionsUsingArray(arr,9,2,0,ar,0);        //saving positions unsing array
   cout<<"count="<<count<<endl;
    for (int i = 0; i < count; i++)
    {
       cout<< ar[i]<<" ";
    }
    cout<< endl;
    string s="1234321";
    cout<<checkPalindron(s,s.length());
  
}
