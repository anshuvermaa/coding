#include<bits/stdc++.h>
using namespace std;
template<typename v>
class mapNode{
    public:
    string key;
    v value;
    mapNode * next;
    mapNode(string key, v value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
};
template<typename v>
class mymap{
// here array type is mapNode<v>*    *this pointer for array memory allocation
    mapNode<v> ** buckets;
    int count;
    int numBuckets;

     int getBucketIndex(string key ){
        int hashcode=0;
        int base=1;
        int p=37;
        for(int i=0; i<key.size(); i++){
            hashcode+=key[i]*base;
            base=base*p;
// we are doing this so that int limit dont cross
            hashcode=hashcode%numBuckets;
            base=base%numBuckets;
        }
        return hashcode%numBuckets;
     }
     void rehash(){
        mapNode<v> ** temp=buckets;
        buckets=new mapNode<v>*[2*numBuckets];
        for(int i=0; i<numBuckets; i++){
            buckets[i]=NULL;
        }
        int oldNumBuckets=numBuckets;
        numBuckets*=2;
        count=0;
        for(int i=0; i<oldNumBuckets; i++){
            mapNode<v>* head=temp[i];
            while(head!=NULL){
                string key=head->key;
                v value = head->value;
                head=head->next;
                insert(key,value);
            }
        }
        for(int i=0; i<oldNumBuckets; i++){
           delete temp[i];
        }
        delete[] temp;
     }
     
    public:
    mymap(){
        count=0;
        numBuckets=5;
// this will create the 5 size array buckets type mapnodes initialized
// with garbag values so in next line we make 
//garbag address NULL by looping over
        buckets = new mapNode<v>*[numBuckets]; 
        for(int i=0; i<numBuckets; i++){
            buckets[i] =NULL;
        }


    }
    ~mymap(){
        for(int i=0; i<numBuckets; i++){
            delete buckets[i];
        }

    }
    int size(){
        return count;
    }


   v getValue(string key){
    int bucketIndex =getBucketIndex(key);
    mapNode<v>* head = buckets[bucketIndex];
    while(head !=NULL){
        if(head->key==key){
            v value=head->value;
            return value;
        }
        head = head->next;
    }
    return 0;
   }
   void insert(string key,v value ){
    // cout<<"key"<<key<<" ";
    int bucketIndex =getBucketIndex(key);
    mapNode<v>* head = buckets[bucketIndex];
    while(head!=NULL){
        if(head->key==key){
            head->value = value;
            return;
        }
    }
    mapNode<v>* node =new mapNode<v>(key,value); 
    node->next=buckets[bucketIndex];
    buckets[bucketIndex]=node;
    count++;
    double loadFactor=(1.0*count)/numBuckets;
    if(loadFactor>0.7){
        rehash();
    }
    
   }
   v remove(string key){
    int bucketIndex =getBucketIndex(key);
    mapNode<v>* head = buckets[bucketIndex];
    mapNode<v>* prev =NULL;
    while(head!=NULL){
        if(head->key==key){
            if(prev==NULL){
                buckets[bucketIndex]=head->next;
            }else{
        prev->next=head->next;

            }
            v value = head->value;
            head->next=NULL;
            delete head;
            count--;
            return value;
        }
        prev =head;
        head=head->next;
    }
    return 0;

   }
};
int main(){
    mymap<int> hmap;
    for(int i=0; i<10;i++){
        char c='c'+i;
        string key="abc";
        key=key+c;
        int value=1;
        value=value+i;
        hmap.insert(key,value);
        cout<<"key: "<<key<<" value "<<hmap.getValue(key)<<endl;
    }
    cout<<hmap.size()<<endl;

    
    return 0;
}