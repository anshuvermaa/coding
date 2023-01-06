
#include <bits/stdc++.h>
using namespace std;
// fabnoci series by method 1 by passing the address of arrray
int fab(int n,int arr[]){
    if(n==0) return 0;
    if(n==1) return 1;
    if(arr[n]!=0){
        return arr[n];
    }
    int output=fab(n-1,arr)+fab(n-2,arr);
    arr[n]=output;
    return output;

}

// method 2 by dynamically creating the array
//butoom to top then filling the array top to bottom
// this is called mimarization

int fab1(int n){
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for (int i=2;i<n+1;i++){
      arr[i]=arr[i-1]+arr[i-2];
    }
    int ans=arr[n];
    delete[] arr;
    return ans;
}

// Q. find the min no of steps to reach 1 u can do -1 and 
// u can devide by 2 and 3 only if they are devisible 


// method 1 by recursion (brudfull approach)
// time complexity=O(3 power n)

int minSteps1(int n){
    if(n<=1) return 0;
    int x=minSteps1(n-1);
    int y,z;
    z=y=INT_MAX;
    if(n%3==0){
        z=minSteps1(n/3);
    }
    if(n%2==0){
        y=minSteps1(n/2);
    }
    int ans=min(x,min(y,z))+1;
    return ans;
}

// method 2 by recursion and DP both ,there will be N unique class
// so complexity O(n) 
// here we are going bottom to top then filing the array top to bottom by recursion
// this technique called memarization
int helpermin(int n,int arr1[]){
        if(n<=1) return 0;
        if(arr1[n]!=-1){
            return arr1[n];
        }
        int x=helpermin(n-1,arr1);
        int y,z;
        z=y=INT_MAX;
        if(n%3==0){
        z=helpermin(n/3,arr1);
    }
    if(n%2==0){
        y=helpermin(n/2,arr1);
    }
    int ans=min(x,min(y,z))+1;
    return ans;

}

int minSteps2(int n){
    int *arr1=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr1[i]=-1;
    }
    int ans=helpermin(n,arr1);
    delete []arr1;
    return ans;
}

// method 3rd here we going to bottom to top symaltenislly filling the array
// Buttom to up DP -> Iterative
int minSteps3(int n){
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=0;
// dp[i]= min steps needed to move from i->1, ans=dp[n]

for(int i=2; i<=n;i++){
int x=dp[i-1];
        int y,z;
        z=y=INT_MAX;
    if(i%2==0){
        y=dp[i/2];
    }
        if(i%3==0){
        z=dp[i/3];
    }
    dp[i]=min(x,min(y,z))+1;

}
int ans=dp[n];
delete[] dp;
return ans; 

}
// 4th best one shortest way possible

int minSteps4(int n){
    int *dp=new int[n+1];
    dp[0]=0;
    dp[1]=0;
// dp[i]= min steps needed to move from i->1, ans=dp[n]

for(int i=2; i<=n;i++){
    dp[i]=dp[i-1]+1;
    if(i%2==0)  dp[i]=min(dp[i],dp[i/2]+1);
    if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
}
int ans=dp[n];
delete[] dp;
return ans; 

}

// staircase problem 
// possile way to climb n stairs either u can take step 1 or 2
// recursive function f(n)=f(n-1)+f(n-2)

// method 1 by recursion
int steps1(int n){
    if (n==0|| n==1) return 1;
    return steps1(n-1)+steps1(n-2);
}

// method 2 by dynamic programming

int steps2(int n){
    int *dp=new int[n+1];
    dp[0]=dp[1]=1;
    for (int i=2; i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    int ans=dp[n];
    delete[] dp;
    return ans;
}
// generalisation of staircase problem by given they can take jump till k
// 1,2 3, . ...k

int steps3(int n,int k){
    int *dp=new int[n+1];
    dp[0]=dp[1]=1;
    for (int i=2; i<n+1;i++){
        int ans=0;
        for (int j=1; j<=k; j++){
           if(j>=0){ ans+=dp[i-j];}
        }
        dp[i]=ans;
    }
    int ans=dp[n];
    delete[] dp;
    return ans;
}

int main(){
    cout<<"3 as shorestest possible   "<<minSteps3(1000000)<<endl;
    cout<<"first by dp and itaratively "<<minSteps3(1000000)<<endl;
    cout<<"first by recursion and dp "<<  minSteps2(500)<<endl;
    cout<<"first by recursion "         <<minSteps1(400)<<endl;
    cout<<"steps: by recursion " <<steps1(10)<<endl;
    cout<<"stepsby dp:        "<<steps2(10)<<endl;
    cout<<"generalised staircase  "<<steps3(10,2)<<endl;

}