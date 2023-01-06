#include<bits/stdc++.h>
using namespace std;

//linear search approach

vector<int> firstAndLastPositionOfElement(int arr[],int n,int x){
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            ans.push_back(i);

        }
    }
    return ans;
}


// implimentation approach by binary serach 

class solution {

/*
    // for first element
    int getFirst(vector<int> &v,int target){
        int s=0;
        int e=v.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;            // (e+s)/2
            if(v[mid]==target){
                ans=mid;
                e=mid-1;
            }else if(v[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }

 /// for last element


        int getLast(vector<int> &v,int target){
        int s=0;
        int e=v.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;            // (e+s)/2
            if(v[mid]==target){
                ans=mid;
                e=mid+1;
            }else if(v[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }




*/
   // in both the functins the only difference is there is only one difference
   // so we can combine the code for memory and code optimijation

      int getIndex(vector<int> &v,int target,bool getfirst){
        int s=0;
        int e=v.size()-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;    // (e+s)/2
            if(v[mid]==target){
                ans=mid;
                if(getfirst){
                    e=mid-1;
                }else{
                e=mid+1;
                }
            }else if(v[mid]<target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }



    vector<int> searchRange(vector<int> &v,int target){
        int first=-1,last=-1;
        vector<int> v1;
        first=getIndex(v,target,true);
        last=getIndex(v,target,false);
        v1[0]=first;
        v1[1]=last;

        return v1;
    }
    
};

int main(){


    int arr[]={1,2,5,3,4,5,6,5,7,};
    vector<int> ans=firstAndLastPositionOfElement(arr,9,5);
    cout<<ans.front()<<endl;
    cout<<ans.back()<<endl;

 
    return 0;
}