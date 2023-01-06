#include<bits/stdc++.h>
using namespace std;

// merge sort its very fast algorithm its uses recursion

void mergeArrays(int x[],int y[],int a[],int s,int e){
       int mid = (s+e)/2;
       int i=s;
       int j = mid+1;
       int k = s;
       while(i<=mid && j<=e){
           if(x[i] < y[j]){
            a[k] = x[i];
            i++;
            k++;
           }else{
             a[k] = y[j];
             j++;
             k++;
           }
       }
       while(i<=mid){
        a[k] = x[i];
        k++;
        i++;
       }
       while(j<=e){
        a[k] = y[j];
        k++;
        j++;
       }
}

void mergeSort(int a[],int s,int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    int x[mid+1],y[e-mid];
    for(int i=s;i<=mid;i++){ 
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    mergeArrays(x,y,a,s,e);
}






 
//quickSort its also follows the recursion algoritham

int partition(int arr[],int s,int e){
    int count = s;
    for(int i=s;i<=e-1;i++){
        if(arr[i]<arr[e]){
            swap(arr[count],arr[i]);
            count++;
        }
    }
    swap(arr[count],arr[e]);
    return count;
}



void quickSort(int arr[],int s,int e){
    if(s>=e) return;
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}




// heap sort by recursion



void heapify(int arr[],int n,int s){
    int pi=s;
    int l=2*s;
    int r=2*s+1;
    if(l<n && arr[l]>arr[pi]){
        pi=l;
    }
    if(r<n && arr[r]>arr[pi]){
        pi=r;
    }
if(pi!=s){
swap(arr[pi],arr[s]);
heapify(arr,n,pi);
}
}

void buildHeap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);

    }
}

int main(){
    int arr[]={4,3,1,5,6,2};
    mergeSort(arr,0,5); 
    for(int i=0;i<=5;i++){ 
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int arr1[]={4,3,1,5,6,2,8};
    quickSort(arr1,0,6); 
    for(int i=0;i<=6;i++){ 
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    int arr2[]={4,3,1,5,6,2,8};
    buildHeap(arr2,7); 
    for(int i=0;i<=6;i++){ 
        cout<<arr2[i]<<" ";
    }
     
    
    return 0;
}