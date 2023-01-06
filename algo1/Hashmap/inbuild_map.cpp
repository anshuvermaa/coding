#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> my_map;
    
    
    
    // insersion by pair
    pair<string,int> p("abc",1);
    my_map.insert(p);
   
   
   
    //second way just like arrays
    my_map["abcd"]=2;

    // accesss
    cout<<my_map["abc"];
    cout<<my_map.at("abcd");
// check presence of a key 

if(my_map.count("abc")){
    cout<<"presence";
}
my_map.erase("abc");
if(my_map.count("abc")){
    cout<<"presence";
}else{cout<<"presence not";}

    return 0;
}