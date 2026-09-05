#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// As you iterate through each number in the array, begin by checking if consecutive numbers like (x+1, x+2, x+3), and so on, exist in the array. The occurrence of the next consecutive number can be checked by using a linear search.
// When you find consecutive numbers, start counting them using a counter. Increment this counter each time you find the next consecutive number in the sequence.
// This counter effectively keeps track of how long the current consecutive sequence is as you move through the array and find more consecutive numbers.
// Dry Run: Please refer to the video for the dry run.
  bool linearSearch(vector<int>& a, int num) {
        int n = a.size(); 
        // Traverse through the array 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }


    // Function to find the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        // If the array is empty
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1; 

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // Current element
            int x = nums[i]; 
            // Count of the current sequence
            int cnt = 1; 

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true) {
                // Move to the next number in the sequence
                x += 1; 
                // Increment the count of the sequence
                cnt += 1; 
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }




 int longestconsectiveSum(vector<int> & nums){
    int n=nums.size();
    if(n==0) return 0; // if there is no elment in array
    // better  approach is 
    // step 1 sort the array
    // decalre variabe maxlen=1 and len =1 
    // if next element = current +1  then update length by 1 
    // if next element== curent then do nothing 
    // finally if next element > current elment then reset the len len=1  start a new sequnce
    // update maxlen with maxlen= max(maxlen,currentlen); ans we have to find maxconsectve sequence
    int maxlen=1;
    int len=1;
    for(int i=0;i<n-1;i++){
        if(nums[i+1]==nums[i]){
            len++;
        }
        else if(nums[i+1]=nums[i]){

        }
        else{
            len=1; // reset the counter

        }
        maxlen=max(maxlen,len);
    }

    return maxlen;
 }

 // first we store element in set unordered
 // then we check current element if its previous element is there we will not start sequence
 // if not there we continously checking if there next element exits increase the current length
 // update max len by max(maxlen,len);
 // return maxlen

 int longestConsectiveElement(vector<int> & nums){
    int n=nums.size();
    if(n==0) return 0;
    unordered_set<int> set;
    //add all element in set
    for(int i=0;i<n;i++){
        set.insert(nums[i]);
    }
     
    int maxlen=1;
    
    for(auto it:set){
        if(set.find(it-1)==set.end()){ // if previous elemnt not exists
            int currentlen=1;
            int x=it;
            while(set.find(x+1)!=set.end()){ // till next element are finding when increase length
                 x=x+1;
                 currentlen++;
            }
            maxlen=max(maxlen,currentlen);//update the length
        }
    }

   return maxlen;
 }

int main(){

}