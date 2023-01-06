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
    int getSize() { return size; }
    bool isEmpty() { return size == 0;}
    void push(T ele) {
        if(size == capacity){
            int j=0;
            T *newArray=new T[2*capacity];
            for(int i=L; i<=capacity; i++){
              newArray[j] = arr[i];
              j++;
            }
            for(int i=0; i<R; i++){
              newArray[j] = arr[i];
              j++;
            }
            delete[] arr;
            arr=newArray;
            L=0;
            capacity = 2*capacity;
            R++;
            size++;

        }
        else{
            
        arr[R]=ele;
       
        
        R=(R+1)%capacity;
        if(L==-1){L=0;}


        size++;

        }
    }
    T front() {
        if(!isEmpty()) {
            return arr[R-1];}
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
    q.push(1);
    q.push(2);
    q.push(3); 
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout<<q.getSize()<<endl;
    q.pop();
    cout<<q.getSize()<<endl;
    cout<<q.front();
    return 0;
}