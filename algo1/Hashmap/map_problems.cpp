#include<bits/stdc++.h>
using namespace std;
// remove duplicates and return vector of unique elements

vector<int> removeDuplicates(int arr[],int n){
    vector<int> ans;
    unordered_map<int,bool> mymap;
 for(int i=0;i<n;i++){   if(mymap.count(arr[i])==0){
        mymap[arr[i]]=true;
        ans.push_back(arr[i]);
    }}
    return ans;
}


int main(){
    int arr[]={1,8,6,2,8,9,10,11,1,2};
    vector<int> ans=removeDuplicates(arr,10);
    for(int i=0;i<ans.size();i++){ 
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}