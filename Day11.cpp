#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 1. Better Approach - O(n^2)
class BetterSolution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum > maxsum) {
                    maxsum = sum;
                }
            }
        }
        return maxsum;   
    }
};

// 2. Kadane's Algorithm - O(n) Time, O(1) Space
class KadaneSolution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int currentsum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            currentsum += nums[i];
            maxsum = max(maxsum, currentsum);
            if (currentsum < 0) {
                currentsum = 0;
            }
        }
        return maxsum;
    }
};

// 3. Kadane's with Subarray Printing - O(n)
class KadaneWithPrintSolution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN; // Fixed from 'long long Long_MIn'
        long long sum = 0;
        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (sum == 0) {
                start = i;
            }

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        // Print the subarray
        cout << "The subarray is: [ ";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;

        return maxi;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    KadaneWithPrintSolution solver;
    int max_sum = solver.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << max_sum << endl;

    return 0;
}