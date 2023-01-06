#include<iostream>
using namespace std;

// print steps in tower of honoi
// tower of honoi count steps required
// staircases problem using steps  1 ,2 ,3 FIND number of ways posible to go up
// printing all the posible permutations
//  remove consecutive  duplicates
//  replace character of string
// print an array in same order




// print an array in same order
void print(int arr[],int n){
    if(n==0) return;
    cout<<arr[0]<<" ";
    print(arr+1,n-1);
}
// print an array in reverse order
void printR(int arr[],int n){
    if(n==0) return;
    print(arr+1,n-1);
    cout<<arr[0]<<" ";
}

// replace character of string

void replaceChar(string &s,int len,char c1,char c2,int i=0){
    if(i==len) return;
    if(s[i]==c1)   s[i]=c2;

    replaceChar(s,len,c1,c2,i+1);
}


// replace character of string

int length(char s[],int i=0){
    if(s[0]=='\0') return 0; 
 return 1+length(s+1,i+1);
 
    
}   

// to work this function properly there should be not space in charrecter array

void removeChar(char s[],char c1){
    if(s[0]=='\0') return;
    if(s[0]!=c1){
        removeChar(s+1,c1);
    }else{
        for(int i=0;s[i]!='\0';i++){
            s[i]=s[i+1];
        }
    }
}



// remove consecutive  duplicates

void removeDuplicates(char s[]){
    if(s[0]=='\0') return;
    if(s[0]!=s[1]) removeDuplicates(s+1);
    else{
        for(int i=0;s[i]!='\0';i++){
            s[i]=s[i+2];
            s[i+1]=s[i+3];
        }
        removeDuplicates(s);
    }
}



// printing all the posible permutations

void printPermu(char s[],int i=0){
    if(s[i]=='\0'){
        cout<<s<<"\n";
        return;
    }
    for(int j=i;s[j]!='\0';j++){
        swap(s[i],s[j]);
        printPermu(s,i+1);
        swap(s[i],s[j]);
    }

}

// staircases problem using steps  1 ,2 ,3 FIND number of ways posible to go up

int countWays(int n){
    if(n==1||n==0) return 1;
    if(n==2) return 2;
    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}


// tower of honoi count steps required

int countTower(int n){
    if(n==0) return 0;
    return countTower(n-1) + 1+countTower(n-1);
}


// print steps in tower of honoi

void printSteps(int n,char s,char d,char h){
    if(n==0) return;
    printSteps(n-1,s,h,d);
    cout<<"Moving disk "<<n <<" from"<<s<<" -->"<<d<<endl;
    printSteps(n-1,h,d,s);

}




int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    print(arr,10);                                                  //printing an array
    cout<<"\n" ;   
    printR(arr,10);
   cout<<"\n" ;
    char s[]="hello how u have been";
    // replaceChar(s,s.length(),'e','i');
    // cout<<s<<"\n";
    cout<<length(s)<<"\n";
     removeChar(s,'e');
    cout<<s;
    cout<<"\n" ;
    char s1[]="aannnvvvvgsafaghhjjj";
    removeDuplicates(s1);
    cout<<s1<<"\n" ;
    char s2[10]="ABC";
    printPermu(s2);
  
   cout<<countWays(4)<<"\n";

   cout <<countTower(3)<<"\n";

   printSteps(3,'A','C','B');

    return 0;
}