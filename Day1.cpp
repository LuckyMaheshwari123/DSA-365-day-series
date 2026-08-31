#include<iostream>
using namespace std;
#include<vector>
#include <climits>
#include <algorithm>


int findLargest(vector<int>& nums){
    //brute force
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return nums[n-1];

}
int findLargestOptimal(vector<int>&nums){
    int n=nums.size();
    int max=nums[0];
    for(int i=0;i<n;i++){
        if(nums[i]>max){
            max=nums[i];
        }

    }
    return max;
}

// --------------------------------------------------------------------------------------------------------------

int findSecondLargest(std::vector<int>& nums) {
    //brute force
    int n = nums.size();
    if (n < 2) return -1; // Handle edge case: fewer than 2 elements

    std::sort(nums.begin(), nums.end());

    int largest = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] != largest) {
            return nums[i];
        }
    }
    return -1; // All elements are identical
}




int secondLargest(const std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1; // Edge case: not enough elements

    // Pass 1: Find the absolute maximum
    int max_val = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }

    // Pass 2: Find the largest value strictly smaller than max_val
    int smax = INT_MIN;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (nums[i] < max_val && (nums[i] >= smax)) {
            smax = nums[i];
            found = true;
        }
    }

    return found ? smax : -1;
}



int optimalSecondLargest(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return -1;

    int max_val = INT_MIN;
    int smax = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (nums[i] > max_val) {
            smax = max_val;
            max_val = nums[i];
        } 
        else if (nums[i] > smax && nums[i] < max_val) {
            smax = nums[i];
        }
    }

    return (smax == INT_MIN) ? -1 : smax;
}

// -----------------------------------------------------------------------------------------------------------------------

//check if array is sorted or not 
bool isSorted(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
        if(nums[i]>nums[j]){
           return false;
        }
       }
    }
    return true;
}

bool isSortedoptimal(vector<int>&nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int>nums={11,7,7,7,7,7};
    // int findlarge=findLargest(nums);
    // int optimal=findLargestOptimal(nums);
    // cout<<"Large is "<<findlarge;
    // cout<<endl;
    // cout<<"Large by optimal approach is:"<<optimal;
    // int second=findSecondLargest(nums);
    // if(second!=-1){
    //     cout<<"second Largest element is:"<<second;
    // }
    // else{
    //     cout<<"there is no second Largest element";
    // }
    // int s=secondLargest(nums);
    // cout<<"seocnd largest is"<<s;
    // int optimalslarge=optimalSecondLargest(nums);
    // cout<<"optimal second Large is:"<<optimalslarge;
    // bool check=isSorted(nums);
    // cout<<check;
     bool check2=isSortedoptimal(nums);
     cout<<check2;

}
