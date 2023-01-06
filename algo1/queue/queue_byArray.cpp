#include<iostream>
using namespace std;
template<typename T>
class Queue{
    int R;
    int L;
    T *arr;
    int size;
    int capacity;
    public:
    Queue(){
        capacity = 5;
        arr=new T[capacity];
        L=-1;
        R=0;
        size = 0;
    }
    Queue(int cap){
       capacity = cap;
       arr=new T[capacity];
        L=-1;
        R=0;
        size = 0;
       
    }
    bool isFull(){ return size == capacity; }
    int getSize() { return size; }
    bool isEmpty() { return size == 0;}
    void push(T ele) {
        if(size == capacity) cout<<"ur Queue is full";
        else{
            
        arr[R]=ele;
       
        
        R=(R+1)%capacity;
        if(L==-1){L=0;}


        size++;

        }
    }
    T front() {
        if(!isEmpty()) {
            return arr[L];}
        else {
            cout<<"ur Queue is Empty";
            return 0;
        }
    }
    void pop(){ 
        if(!isEmpty()){
            L=(L+1)%capacity;
            size--;
            if(size==0){
                R=0;
                L=-1;
            }
        }

    }
};

int main(){
    Queue<int> q;
    cout<<"isEmpty: ";
   if(q.isEmpty())cout<<"true"<<endl; cout<<"false"<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
     q.push(6);
  
    cout<<"size:"<<q.getSize()<<endl;

    cout<<"isFull: ";
   if(q.isFull())cout<<"true"<<endl;else cout<<"false"<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front();
    return 0;
}