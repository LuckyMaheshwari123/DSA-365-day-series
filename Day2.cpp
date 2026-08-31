//move zero to end
#include <bits/stdc++.h>
using namespace std;

    void moveZeroes0(vector<int>& nums) {
        int n=nums.size();
        // int pos=0;
         int j = -1;

        // Find the first zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }
        if(j==-1)return;
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }

// ----------------------------------------------------------------------------------------------------------------
//brute force approach will be 
// first shift all nonzero element from starting from first index
//the add remaining zero from index to n

    void moveZeroes1(vector<int>& nums) {
        int n=nums.size();
        int index=0;
        //non zeros
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }
        }
//zeros
        for(int j=index;j<n;j++){
            nums[j]=0;
        }
    }


// ----------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

// -----------------------------------------------------------------------------------------------------------------------------
void rotateLeftBruteForce(std::vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= 1) return;

    k = k % n; // Handle k >= n

    for (int step = 0; step < k; step++) {
        int first = nums[0]; // Save the first element
        
        // Shift every element one step to the left
        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }
        
        nums[n - 1] = first; // Place the saved element at the back
    }
}
// ------------------------------------------------------------------------------------------------------------
void leftroatearray(vector<int>&nums){
    int n=nums.size();
    int first=nums[0];
    for(int i=0;i<n-1;i++){
        nums[i]=nums[i+1];
            
    }
    nums[n-1]=first;
}
// -------------------------------------------------------------------------------------------------------------

// Function to search for a number in the array
int search(int arr[], int n, int num)
{
    int i;

    // Loop through the array to find the number
    for(i = 0; i < n; i++)
    {
        // If the current element matches the number, return its index
        if(arr[i] == num)
            return i;
    }

    // If the number is not found, return -1
    return -1;
}

int main()
{
    // Declare and initialize the array
    int arr[] = {1, 2, 3, 4, 5};

    // Number to search for
    int num = 4;

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the search function and store the result
    int val = search(arr, n, num);

    // Print the index of the found number or -1 if not found
    cout<<val;

    return 0;
}
