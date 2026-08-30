#include<iostream>
#include<vector>
#include <vector>
#include <algorithm>

int subarray(const std::vector<int>& nums, int k) {
    int n = nums.size();
    int maxLength = 0;
    int left = 0;
    long long sum = 0;

    // idea is simple 
    // we will loop from 0 to n  and inside the loop we maintain sum variabe and add current element in window 
    // if the left <=right && sum>k and then we remove nums[left ] from window move the left pointer by1
    // if sum ==k then we simply take maximum of current lenght(right-left+1) with our maxLength
    // return the maxelength
    // time complexity 0(n) we iterate from 1 to n and other as just constant opreation
    // space complexity o(1)

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        // Shrink the window from the left while sum exceeds k
        while (left <= right && sum > k) {
            sum -= nums[left++];
        }

        // Check for match
        if (sum == k) {
            maxLength = std::max(maxLength, right - left + 1);
        }
    }

    return maxLength;
}

#include <vector>
#include <algorithm>
//brute force approch 
//generate all subarray
//calcuate that subarray sum
//cacluate length  and update the maxelength with current length

int subarray(const std::vector<int>& nums, int k) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            // Renamed loop variable to 'idx' to avoid shadowing target 'k'
            for (int idx = i; idx <= j; idx++) {
                sum += nums[idx];
            }

            if (sum == k) {
                maxLength = std::max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

#include <vector>
#include <unordered_map>
#include <algorithm>

int longestSubarrayWithSumK(const std::vector<int>& nums, int k) {
    std::unordered_map<long long, int> prefixMap;
    long long sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        // Case 1: Subarray starting from index 0
        if (sum == k) {
            maxLength = i + 1;
        }

        // Case 2: Subarray starting after an earlier prefix sum
        long long rem = sum - k;
        if (prefixMap.find(rem) != prefixMap.end()) {
            maxLength = std::max(maxLength, i - prefixMap[rem]);
        }

        // Case 3: Store only the first occurrence of this prefix sum
        if (prefixMap.find(sum) == prefixMap.end()) {
            prefixMap[sum] = i;
        }
    }

    return maxLength;
}