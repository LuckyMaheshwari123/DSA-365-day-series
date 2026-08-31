#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include<vector>
//boyre more voting algoritham
// Intuition: Pairwise Cancellation
// Since the majority element appears > n/2 times, even if every non-majority
// element pairs up to cancel out one vote of the majority element (count--),
// the majority element will still have at least 1 vote left standing (count > 0).
int majorityElement(vector<int>&nums){
    int n=nums.size();
    int count=0;
    int element=0;
    for(int i=0;i<n;i++){
        //
        if(count==0){
            count=1;
            element=nums[i];
        }
        else if(nums[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
}
int majorityOptimal(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return nums[n/2];
    }
int majorityElementBetter(vector<int>&nums){
    unordered_map<int,int>frequecyCount;
    int n=nums.size();
    for(int i=0;i<n;i++){
        frequecyCount[nums[i]]++;
    }
    n=n/2;
    for(auto x:frequecyCount){
        if(x.second>n){
            return x.first;
        }
    }
    return 0;
}

int majorityElementBrute(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Iterate through each element of the array
        for (int i = 0; i < n; i++) {
            
            // Counter to count occurrences of nums[i]
            int cnt = 0; 
            
            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            
            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2)) {
                // Return the majority element
                return nums[i]; 
            }
        }
        
        // Return -1 if no majority element is found
        return -1; 
    }

int main(){

}
