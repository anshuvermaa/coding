// recursion

//checking array sorted or not 
//fabanoci
// factorial
// power
// counting zeroes in a number     *******
 // multiplication
 //digit sum 
 //number of digits



#include<iostream>
using namespace std;





// fabanoci by recursion
long fab(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fab(n-1)+fab(n-2);
}


//factorial using recursion
long fact(int n){
    if(n==0) return 1;
     return n*fact(n-1);
}


// power using recursion
 long pow(int num,int pw){
    int num1;
    if(pw==0) return 1;
    num1= num*pow(num,pw-1);
    return num1;
}


// number of digits in a number
int num_digit( long num){
    if(num==0) return 0;
    return 1+num_digit(num/10);
}

// some of digits in the given numbers
int sum_digit( long num){
    if(num==0) return 0;
    return num%10+sum_digit(num/10);
}

// multiplication by recursion
long multiply(int a,int b){
    if(b==0) return 0;
    return a+multiply(a,b-1);
}


// count zeroes by recursion
int count_zeros(long long num){
    if(num==0) return 0;
  int smallans=count_zeros(num/10);
  int last_digit=num%10;
  if(last_digit==0) return 1+smallans;
  else return smallans;
    
}



int main(){
    cout<<num_digit(27890)<<"\n";               //number of digits
    cout<<sum_digit(27890)<<"\n";               //digit sum 
    cout<<multiply(10,20)<<"\n";                // multiplication
    cout<<count_zeros(38001800660)<<"\n";       // counting zeroes in a number     *******
    cout<<pow(3,3)<<"\n";                       // power
    cout<<fact(3)<<"\n";                        // factorial
    cout << fab(4)<<"\n";                       //fabanoci



    return 0;

}



