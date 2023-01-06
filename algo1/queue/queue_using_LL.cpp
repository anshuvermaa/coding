#include<iostream>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node* next;
    
    Node(int data){
        this->data=data;
        next=NULL;
        }

};
template<typename T>
class Queue {
    public:
    Node<T>* head;
    Node<T>* tail;
    int size;

    Queue(){
      Node<T>* head=NULL;
      Node<T>* tail=NULL;
        size=0;
    }
    int getSize() {
         return size;}
    bool isEmpty() { return size==0;}
    void push(T ele){
      
    
        if(isEmpty()){
            Node<T>* n=new Node<T>(ele);
            head=n;
            tail=n;
            size++;
              
        }else if(!isEmpty()){
            Node<T>*n=new Node<T>(ele);
            head->next=n;
            n->next=tail;
            head=n;
            size++;
        }
    }
    T front() { 
        if(isEmpty()){return 0;}else{

            return tail->data;
        }
        


    }
    void pop() {
        if(isEmpty()){cout<<"queue is empty";}
        else{
            Node<T>* temp=tail;
            //  cout<<tail->data; 
            tail=temp->next;
            free(temp);
            delete temp;
            size--;

        }
    }


};

int main(){
    Queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    // cout<<q.front()<<endl;
    // cout<<q.getSize()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
        q.push(16);
  
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;

    return 0;
}