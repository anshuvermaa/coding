// mejority element >= n/2



#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &v){
    int card=v[0];
    int count=0;
    int n=v.size()-1;
    for(int i=0; i<n;i++){
        if(v[i]==card){
            count++;
        }else{
            count--;
            if(count==0){
                card=v[i];
                count=1;
            }
        }
        
    }
        int count2=0;
        for(int i=0;i<n;i++){
            if(v[i]==card){
                count2++;
            }
        }
        if(count2>n/2){
            return card;
        }
        else{
            cout<<"mejority element doesn't exist";
            return 0;
        }
}


int main(){


    vector<int> v={2,1,1,1,3,1,2,1,1,2,1,1,4,5,6,3};
    cout<<majorityElement(v);
    
    return 0;
}