#include<iostream>
using namespace std;

class stack{
    int *arr;
    int nextIndex;
    int capacity;
public:
    stack(){
        arr=new int[4];
        nextIndex=0;
    }
    // stack(int cap){
    //     capacity=cap;
    //     arr=new int[capacity];      //we take capacity only for static stack not for dynamic stack and we also need to update the push method
    //     nextIndex=0;
    // }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int elem){
        if(capacity==nextIndex){
          capacity=2*capacity;
          int *newarr=new int[capacity];
          for(int i=0;i<capacity/2;i++){
              newarr[i]=arr[i];
          }
          delete []arr;
          arr=newarr;
        }
        arr[nextIndex]=elem;
        nextIndex++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return ;
        }
        nextIndex--;
    }
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return arr[nextIndex-1];
    }

};

int main(){
    stack s;
    cout<<s.size()<<endl;
    s.push(10);
    s.push(11);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
//     s.push(12);
//     cout<<s.top()<<endl;
//     s.pop();
//     cout<<s.top()<<endl;
//     s.push(13);
//     cout<<s.top()<<endl;
//     s.push(14);
//      cout<<s.size()<<endl;
//      cout<<s.isEmpty()<<endl;
//      stack s2;
//      for(int i=1;i<=9;i++){
//    s2.push(i);
//      }
//      for(int i=9;i>=1;i--){
//          cout<<s2.top()<<endl;              //printing the top value and deleting it
//    s2.pop();
//      }
    return 0;
}