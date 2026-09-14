#include<bits/stdc++.h>
using namespace std;


int countSpecialIntegers(vector<int>& nums) {
         unordered_map<int, vector<int>> mp;

    // Store indices of each element
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = 0;

    for (auto &it : mp) {

        // Must occur exactly 3 times
        if (it.second.size() == 3) {

            int i1 = it.second[0];
            int i2 = it.second[1];
            int i3 = it.second[2];

            if (i2 - i1 == i3 - i2) {
                ans++;
            }
        }
    
    }
    return ans;
}
    // ------------------------------------------
int countSpecialIntegers(vector<int>& nums) {
           unordered_map<int, vector<int>> mp;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = 0;

    for (auto &it : mp) {

        vector<int>& pos = it.second;

        if (pos.size() < 3)
            continue;

        int diff = pos[1] - pos[0];

        bool special = true;

        for (int i = 2; i < pos.size(); i++) {
            if (pos[i] - pos[i - 1] != diff) {
                special = false;
                break;
            }
        }

        if (special)
            ans++;
    }

    return ans;
};


 long long distantSubarrays(vector<int>& nums, int goal, int k) {
        long long n= nums.size();
        int c=0;
        for(long long i=0;i<n;i++){
            long long sum=0;
            for(long long j=i;j<n;j++){
                sum+=nums[j];
                if(abs(sum-goal)>=k){
                    c++;
                }
            }
        }
        return c;
    }
   