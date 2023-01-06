#include<iostream>
using namespace std;


int searchIndex(int arr[],int n,int x){
    int s=0;
    int e=n-1;
    while(s<=e){
    int mid=s+(e-s)/2;
    if(arr[mid]==x){
        return mid;
    }else if(arr[mid]<x){
        s=mid+1;
    }else{ 
        e=mid-1;
    }

        
    }
    return -1;
}

int main(){

    int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<searchIndex(arr,9,6);
    
    return 0;
}