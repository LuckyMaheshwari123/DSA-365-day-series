#include<iostream>
using namespace std;
#include<vector>

#include <iostream>
#include <vector>

using namespace std;
//brute force
int singleNumber(const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count == 1) {
            return nums[i];
        }
    }
    return -1; // Fallback if no single element exists
}



//optimal appraoch it take o(3N) time and space O(maxelement+1)
    // Function to find the single non-repeating element using a hash array
    //you can use map instead of hashing
    int getSingleElement(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Find the maximum value in the array
        int maxi = arr[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
        }

        // Step 2: Declare and initialize hash array of size maxi+1
        vector<int> hash(maxi + 1, 0);

        // Step 3: Count the frequency of each number
        for (int i = 0; i < n; i++) {
            hash[arr[i]]++;
        }

        // Step 4: Find the element that occurs exactly once
        for (int i = 0; i < n; i++) {
            if (hash[arr[i]] == 1)
                return arr[i];
        }

        return -1; // fallback, shouldn't occur in valid input
    }

    //this techncique is simple 
    // property for xor when it xor with it self it is zero
    //since there are number appreaing twice so it cancel out and only number that appears once remain 
    //O(N) space:o(1)
int singleNumberXor(const vector<int>&nums){
    int n=nums.size();
    int Xor=0;
    for(int i=0;i<n;i++){
         Xor^=nums[i];
    }
    return Xor;
}



int main() {
    vector<int>num ={1, 1, 2, 2, 3, 4, 4};
    int m = singleNumberXor(num);
    cout << "the number is " << m << endl;
    return 0;
}
