#include <bits/stdc++.h>
using namespace std;
// brute force approach 
// first store positive in positive array
// store negative in negative array
// then merge them using pointer
// if index is even take element from positive store it
// if odd then negative 
// here order maintain
// time complexity O(2N) // for counting and merging
// space complexity O(N) // for storing positive and negative

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
         // iterate through array and satisfy first 3rd condtion
         int n=nums.size();
          vector<int>positive;
          vector<int>negative;
          for(int i=0;i<n;i++){
            if(nums[i]>=0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
          }
        int i=0;
        int j=0;
        int k=0;
        while(i<n){
            if(i%2==0){
                nums[i]=positive[j];
                i++;
                j++;
            }
            else{
                nums[i]=negative[k];
                i++;
                k++;
            }
        }
     return nums;   
    }
};


// optimal approach 
// in this apporach we try to reduce to time compelxity from O(2N) to o(n) as we can not remove space complexity
// because it is rearraging so we need to store some there 
// in this approach we will intilaize an array ans with element with 0 and two pointer positveindex=0 and negative index =1
// iterate through array if element is positive then we store in ans and increase psitive index by 2 
// same for negative if element is negative then we store in negative index of ans and increase negative index by 2

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>store(n,0);
        int pindex=0;
        int nindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                store[nindex]=nums[i];
                nindex+=2;
            }
            else{
                store[pindex]=nums[i];
                pindex+=2;
            }
        }
        return store;
    }
};
int main(){

}