#include<iostream>
using namespace std;
#include<vector>
int missingNum(vector<int>& arr) {
    int n = arr.size() + 1;

    //since we have to finding missing element 
    // iterate from 1 to size of arraay
    //if this element present then ok break the loop 
    //if not found that is our element missing
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }

        // If the current number is not present
        if (!found)
            return i;
    }
    return -1;
}


int missingNum1(vector<int> &arr) {
     // in this approach we declare a hash and stored the frequencey foor element 
     // and iterae through map and which element in our map have zero frequency that is our missing number
    int n = arr.size() + 1;

    // Create hash array of size n+1
    vector<int> hash(n + 1, 0);

    // Store frequencies of elements
    for (int i = 0; i < n - 1; i++) {
        hash[arr[i]]++;
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}


//optimal appraoch
int missingNumber(vector<int>&nums){
    int n=nums.size();
    int expectedsum=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return expectedsum-sum;
}
int missingNumberxor(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]^(i+1)!=0){
            return nums
        }
    }
}
#include <iostream>
#include <vector>
using namespace std;

int missingNum(vector<int>& arr) {
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    // Missing number is the XOR of xor1 and xor2
    return xor1 ^ xor2;
}

int main() {
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1}; 
    int res = missingNum(arr);  
    cout << res << endl;  
    return 0;
}
int main(){

}