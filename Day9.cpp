#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//use sorting algoritham this is bubble sort 
// brute force algoritham O(n^2) 
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to detect if array is already sorted

        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, array is sorted
        if (!swapped) {
            break;
        }
    }
    }

    void sortColorsbetter(vector<int>&nums){
    //since array contain only 0 1 and 2 
    //count 0 1 and count 2
    //place back to array
    int c0=0,c1=0,c2=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            c0++;
        }
        else if(nums[i]==1){
            c1++;
        }
        else{
            c2++;
        }
    }
   int index=0;
   //place zero
   while(c0){
      nums[index++]=0;
      c0--;
   }
   while(c1){
    nums[index++]=1;
    c1--;
   }
   while(c2){
    nums[index++]=2;
    c2--;
   }


    }
//duth national flag algoritham

//intitutation
// evey thing from 0 to low-1 is 0 //sorted
// every thing from low to mid-1 is 1 //sorted
// every thing from high+1 to n-1 is 2 //sorted
// mid to high is random numbers //sort this portion
// we solve this solution of a[mid] three possible 0 1 2
// if 0 then we swap a[mid] with a[low] mid++, low++;
//if 1 then we just mid++ because it sorted
//if 2 then just swap a[high] with mid high--;
void sortColorsOptimal(vector<int>&nums){
    int n=nums.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}