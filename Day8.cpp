#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//brute force approach
 vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<int>V;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                V.push_back(i);
                V.push_back(j);
                break;
            }
        }
    }
    return V;
        
}


vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    unordered_map<int,int>store;
    for(int i=0;i<n;i++){
         int complement = target-nums[i];
         if(store.count(complement)){
            return {store[complement],i};
         }
         store[nums[i]]=i;
    }
    return {};
        
}
// this apporach only apply to when we have to tell yes or no 
//we can correct return index because during sorting index are shuffled
 bool twoSumTwopointer(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<=j){
            if(nums[i]+nums[j]==target){
                return "true";
            }
            else if (nums[i]+nums[j]>target){
                j--;
            }
            else {
                i++;
            }
        }
        return false;

    }

//letcode 167 two sum when array is already sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(numbers[i]+numbers[j]==target){
               return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else{
                i++;
            }

        }
        return {};
    }
    
};

int main(){

}