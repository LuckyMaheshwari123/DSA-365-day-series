

//brute force approach genearate all subarray  and do sum if sum 0 then return length

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Optimal Hash Map Approach: O(N) Time, O(N) Space
int longestSubarrayZero(const vector<int>& nums) {
    int n = nums.size();
    long long sum = 0; // Using long long prevents integer overflow
    int maxlen = 0;
    unordered_map<long long, int> sumIndexMap;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum == 0) {
            maxlen = i + 1;
        }

        // If this prefix sum has been seen before, calculate subarray length
        if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxlen = max(maxlen, i - sumIndexMap[sum]);
        } else {
            // Only store the first occurrence of the prefix sum to maximize length
            sumIndexMap[sum] = i;
        }
    } 
    return maxlen;
}
int main(){

}