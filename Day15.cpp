#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

// brute force approach  we pick the element 
// and check if it right element are less then it is leader
//store in ans 
//Time complexity O(N*N)
//space complexity O(1);//as it is constant space not depend on input

vector<int> leaders(vector<int> &nums){
    int n=nums.size();
    vector<int> ans;

    for(int i=0;i<n;i++){
         bool leader =true;
         // check wheter nums[i] is greater than all element to right
         for(int j=i+1;j<n;j++){
            if(nums[j]>=nums[i]){
                //if any element to right is greater of equal nums[i] not leader
                leader=false;
                break;
            }
         }
         if(leader){
            ans.push_back(nums[i]);
         }
    }
   return ans;
}

//  4 7 1 0 ans = 0
//  max=0;
// 1 1>0 max=1 push in ans 0,1
// 7 7>1 max=7 push in ans 0,1,7
// 4 4>7 not 
// ans= 0 1 7
// reverse 0 1 7 = 7 1 0
// that is the ans
 

vector<int> Leaders(vector<int> &nums){
    vector<int> ans;
    if(nums.empty()){
        return ans;
    }
    int n=nums.size();

    //Last element of array is always a leader

    int max= nums[n-1];
    ans.push_back(max);
    // check from right to left 
    for(int i=n-2;i>=0;i--){
        if(nums[i]>max){
            ans.push_back(nums[i]);
            max=nums[i];
        }
    }
    // now this result is reverse order because we traverse from right to left
    // so we reverse the result to get desired result
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){

}