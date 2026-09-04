#include <bits/stdc++.h>
using namespace std;
//brute force apporach
//genearte all possible permuation
// do a linear search of current permuation
// return next index 
// if not exist return first index
class Solution {
public:
    // Function to find the next permutation
    vector<int> nextPermutation(vector<int>& nums) {
        // Store all permutations
        vector<vector<int>> all;

        // Generate all permutations
        sort(nums.begin(), nums.end());
        do {
            all.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        // Traverse the list to find current permutation
        for (int i = 0; i < all.size(); i++) {
            if (all[i] == nums) {
                // If it's the last permutation
                if (i == all.size() - 1)
                    return all[0];
                // Return the next one
                return all[i + 1];
            }
        }

        // Return original if not found (shouldn't happen)
        return nums;
    }
};

// otimal solution
// Traverse from the end and find the first index where the current digit is smaller than the next one (this is the "breaking point").
// Then again traverse from the end to find the first digit greater than the breaking point digit and swap them.
// Finally, reverse the part of the array to the right of the breaking point to get the smallest next permutation.
// If no such breaking point exists (entire array is descending), just reverse the whole array.

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<int> result = sol.nextPermutation(nums);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
