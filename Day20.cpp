#include<bits/stdc++.h>
using namespace std;


    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        //generate all subrray and sum this if sum=k and increase count
        // return the count;
        // Big O (N^3) time 
        //brute force
        int count=0;
        for(int i=0;i<n;i++){
              for(int j=i;j<n;j++){
                int sum=0;
                for(int m=i;m<=j;m++){
                    sum+=nums[m];
                }
                if(sum==k){
                    count++;
                }
              }
              
        }
        return count;
    }


// better approach 
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
          //intituon is that 
// We want to find how many continuous subarrays have a sum equal to k.
// Start from each index i.
// Keep extending the subarray using j.
// Add each new element to sum.
// If sum == k, we found a valid subarray, so increase count.

        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
              for(int j=i;j<n;j++){
                sum+=nums[j];
                
                if(sum==k){
                    count++;
                }
              }
              
        }
        return count;
    }

#include <bits/stdc++.h>
using namespace std;


    // Function to find count of subarrays with sum equal to k using prefix sums and hashmap
    int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Map to store frequency of prefix sums
        unordered_map<int, int> prefixSumCount;

        // Initialize prefix sum and count of subarrays
        int prefixSum = 0;
        int count = 0;

        // Base case: prefix sum 0 has occurred once
        prefixSumCount[0] = 1;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Add current element to prefix sum
            prefixSum += arr[i];

            // Calculate the prefix sum that needs to be removed
            int remove = prefixSum - k;

            // If this prefix sum has been seen before,
            // add its count to the result
            if (prefixSumCount.find(remove) != prefixSumCount.end()) {
                count += prefixSumCount[remove];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[prefixSum]++;
        }

        // Return the total count of subarrays
        return count;
    }





