#include<bits/stdc++.h>
using namespace std;

// LEVEL - EASY
// Q1.-> given an array of integers return that indices of two numbers that add up to a given target

vector<int> targetIndex1(vector <int> &nums,int target){
    vector <int> v={-1,-1};
 for(int i = 0; i < nums.size()-1;i++){
    for(int j = i+1; j < nums.size();j++){
    if(nums[i]+nums[j]==target){
        v.resize(0);
        v.push_back(i);
         v.push_back(j);
        
        return v;

    }

    }
 } 
        return v;
}
// optimised version

// since we are using sencond for loop to check if that value exist in our array or not
// so we can make a hash map
// unordered_map<key,value> name


vector<int> targetIndex(vector <int> &nums,int target){
  
    unordered_map<int,int> m;
 
for(int i=0; i<nums.size();i++){
   int res=m[nums[i]];
   if(res>0){
    return {res-1,i};
   }else{
   int numToFind=target-nums[i];
   m[numToFind]=i+1;
  

   }
   }
}

// LEVEL - MEDIUM
// Q.2-> Max area Water container

int maxWaterContainer(vector <int> &height){
    int maxArea=0;
    for(int i=0; i<height.size();i++){
        for(int j=i+1; j<height.size();j++){
            int maxA=min(height[i],height[j])*(abs(j-i));
            if(maxA>maxArea) maxArea=maxA;
        }
    }
    return maxArea;
}

// optimised version

int maxWaterContainer1(vector <int> &height){
    int maxArea=0,i=0,j=height.size()-1;
    while(i<j){
        int maxA=min(height[i],height[j])*(abs(j-i));
        maxArea=max(maxA,maxArea);
        if(height[i]<height[j]) i++;
        else j--;
    }
    
    return maxArea;
}


// LEVEL - HARD
// problem-> Trapping rain water
// Water units calculations

int waterUnits(vector <int> &levels){
    int total=0;
    for(int i=0;i<levels.size();i++){
        int cH=levels[i], maxL=0,maxR=0;
        int leftP=i, rightP=i;
        while(leftP>=0){
            maxL=max(maxL,levels[leftP]);
            leftP--;
        }
        while(rightP<levels.size()){
            maxR=max(maxR,levels[rightP]);
            rightP++;
        }
        int currentWater=min(maxL,maxR)-levels[i];
        // only if we are adding if currentWater is positive
        if(currentWater>=0){
            total+=currentWater;

        }
    }
    return total;
}


// optimised version

int waterUnits1(vector <int> &levels){
    int maxL=0,maxR=0,total=0;
    int PL=0,PR=levels.size()-1;
    while(PR>PL){
        if(levels[PL]<=levels[PR]){
            if(levels[PL]>= maxL){
                maxL=levels[PL];
          
          }else{

           total+=maxL-levels[PL];
          }
          PL++;
        }else{
            if(maxR<=levels[PR]){
                maxR=levels[PR];
      
          }else{

          total+=maxR-levels[PR];
          }
          PR--;

        }
    }
        return total;
}




 
 





int main(){
    // array target value
    vector <int> v{3,4,2};
    vector<int> an=targetIndex(v,6);
    // vector<int> an=targetIndex1(v,6);
    cout<<"first index is "<<an[0]<<"\nsecond index is "<<an[1]<<endl;
     vector <int> v2{1,9,2,7,4};
     cout<<maxWaterContainer(v2)<<endl;
     cout<<maxWaterContainer1(v2)<<endl;
     vector <int> v3{4,2,0,3,2,5};
     cout<<waterUnits(v3)<<endl;
     cout<<waterUnits1(v3)<<endl;
    
    return 0;
}