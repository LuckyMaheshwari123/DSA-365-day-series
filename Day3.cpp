#include<iostream>
#include <bits/stdc++.h>
using namespace std;

    int removeDuplicates(vector<int>& nums) {
         unordered_set<int> seen;
         int n=nums.size();
         int index=0;
         for(int i=0;i<n;i++){
            if(seen.find(nums[i])==seen.end()){//not exists
                seen.insert(nums[i]);
                nums[index]=nums[i];
                index++;

            }
         }
        return index;
    }
// --------------------------------------------------------------------------------------------------------------------------------------
    //optimal

    int removeDuplicatesOptimal(vector<int>&nums){
        if (nums.empty()) return 0;
        int n=nums.size();
        int index=1;
        //since first element is unique we starts loop from one 
        //and check if current element is not equla to previous element 
        // we store at this index and increment index else skip
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
// -------------------------------------------------------------------------------------------------------------------------

//union of two sorted array

class Solution {
public:
//set approach
    // Function to find the union of two arrays using set
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        //insert element from list1 to a set
        //insert element from list2 to a set
        //set should be ordered because unordered have random
        //convert set into list
        //return this


        // Create a set to store unique elements
        set<int> st;

        // Insert elements from first array
        for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }

        // Insert elements from second array
        for (int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }

        // Convert set to vector
        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
    }
};

#include <bits/stdc++.h>
using namespace std;

// Define the Solution class
//approach is simple 
// here we use orderd map 
//first store the element frequency from list1
//store the telement frequencey from list2
//iterate through map and store element in a union list
    // Function to find union of two arrays
    vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
        // Create a map to store frequency of each element
        map<int, int> freq;
        // Create a vector to store the union result
        vector<int> Union;
        // Loop through first array and store frequency
        for (int i = 0; i < n; i++)
            freq[arr1[i]]++;
        // Loop through second array and store frequency
        for (int i = 0; i < m; i++)
            freq[arr2[i]]++;
        // Traverse the map to get unique sorted elements
        for (auto &it : freq)
            Union.push_back(it.first);
        // Return the union vector
        return Union;
    }
// vector<int> findIntersection(const vector<int>& A, const vector<int>& B) {
//     vector<int> result;
//     int p1 = 0, p2 = 0;
    
//     while (p1 < A.size() && p2 < B.size()) {
//         if (A[p1] == B[p2]) {
//             result.push_back(A[p1]);
//             p1++;
//             p2++;
//         } else if (A[p1] < B[p2]) {
//             p1++; // A's element is smaller, move forward
//         } else {
//             p2++; // B's element is smaller, move forward
//         }
//     }
//     return result;
// }

#include <bits/stdc++.h>
using namespace std;

    // Function to find union of two sorted arrays using two pointers
    vector<int> findUnionOptimal(int arr1[],int arr2[],int n,int m){
        vector<int>Union;
        int i=0,j=0;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                 if (Union.empty() || Union.back() != arr1[i])//check last elemnt added in not arr1[i] to avoid copy
                    Union.push_back(arr1[i]);
                    i++;
            }
            else if(arr1[i]>arr2[j]){
                 if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                    j++;
            }
            else{
                 if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                    i++;
                    j++;
            }
        }
        //add remaining elmenets
        while(i<n){
         if (Union.empty() || Union.back() != arr1[i]){
                    Union.push_back(arr1[i]);  
                    i++;  
         }
        }
        while(j<m){
             if (Union.empty() || Union.back() != arr2[j]){
                    Union.push_back(arr2[j]);
                    j++;
             }
        }
    
        return Union;
        
    }
    





int main(){

}
