#include<bits/stdc++.h>
using namespace std;
class PriorityQueue{
    public:
    vector<int> v;

    int getPatentIndex(int ci) { 
       return (ci-1)/2;
    }
    PriorityQueue(){

    }
    bool isEmpty(){
        return v.size() == 0;
   }
   int getSize(){
    return v.size();
   }
   int getMin(){
    if(!isEmpty()) return v[0];
    else return 0;
   }
      void insertV(int element){
         v.push_back(element);   /// CBT yes, Heap not

         int cI = v.size() - 1;
         while(cI > 0){
            int pI = (cI-1)/2;
            if(v[cI] < v[pI]){
                swap(v[cI], v[pI]);
                cI = pI;
            }else {
               break;
            }
        }
    }

  int removeMin(){
    if(!isEmpty()){
        int ans=v[0];
        swap(v[0],v[v.size()-1]);
        v.pop_back();
     // CBT property YES but min heap property no
     // so we will do down heapify
     int pi=0;
     while(true){
      int lci=2*pi+1;
      int rci=2*pi+1;
      int mini=pi;
      if(lci <v.size() && v[mini]>v[lci]){
        mini=lci;
      }
      if(rci <v.size() && v[mini]>v[rci]){
        mini=rci;
      }
      if(mini==pi){
        break;
      }
      swap(v[mini],v[pi]);
      pi=mini;

     }
        return ans; 
    }else{
        return 0;
    }
  }
    

};
// inplace heap sort


void inplaceHeapSort(int arr[],int n){
  // build heap in input array
 
  for(int i=1;i<n;i++){
    int ci=i-1;
    while(ci>0){
     int pi=(ci-1)/2;
     if(arr[ci]<arr[pi]){ swap(arr[ci],arr[pi]); ci=pi;}
     else{ break;
     }
    }
  }

  // remove min n times
  int s=n;

  while(s>=1){
   int pi=0;
    swap( arr[0],arr[s-1]);
     s--;
   while(true){
    int lci=2*pi+1;
    int rci=2*pi+2;
    int mini=pi;
    if(lci<s && arr[mini]>arr[lci]){ 
      mini=lci;
    }
    if( rci<s && arr[mini]>arr[rci]){
      mini=rci;
    }
    if(pi==mini) break;
    swap(arr[mini],arr[pi]);
    pi=mini;
   }
   

  }



}


// k sorted array

void kSortedArray(int input[],int n,int k ){
  priority_queue<int> q;
  for(int i=0;i<k;i++) q.push(input[i]);
  int s=0;
  for(int i=k;i<n;i++){
    input[s]=q.top();
    q.pop();
    s++;
    q.push(input[i]);
  }
  while(!q.empty()){
    input[s]=q.top();
    q.pop();
    s++;
  }
  
}

// k smallest numbers
void ksmallest(int input[],int n,int k){
  priority_queue<int> q;
  for(int i=0;i<k;i++) q.push(input[i]);
  for(int i=k;i<n;i++){
    if(q.top()>input[i]){
      q.push(input[i]);
      q.pop();
    }
  }
  while (!q.empty())
  {
    cout << q.top() <<" ";
    q.pop();
  }
   
}



int main(){

   PriorityQueue p;
   for (int i = 10; i > 5; i--)
   {
    p.insertV(i);
   }
 
    while(!p.isEmpty()){
        cout<<p.removeMin()<<"->" ;
    }

cout<<endl;
  int arr[]={1,2,3,4,5,6,8,7};

  inplaceHeapSort(arr,8);
  for(int i=0;i<8;i++) cout<<arr[i]<<" ";
  cout<<endl;
  int arr1[]={10,12,20,6,7,9};
  kSortedArray(arr1,6,3);
    for(int i=0;i<5;i++) cout<<arr1[i]<<" ";

  cout<<endl;
   ksmallest(arr1,6,3);

    return 0;
}