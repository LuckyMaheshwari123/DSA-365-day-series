#include<iostream>
using namespace std;
#include<vector>
#include <bits/stdc++.h>

//brute force approach to solve this maxprofit
//approach is simple we iterate through element and the check every element
//and do difference store in variabe as running profit and continously checking
//if running profit > maxprofit then maxprofit =running profit 
// it take O(N^2) time 
// it take space O(1) 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxprofit = 0;
        int n = prices.size();
        
        for(int i = 0; i < n; i++) {
            int profit = 0;

            for(int j = i; j < n; j++) {
                profit = prices[j] - prices[i];

                if(profit > maxprofit) {
                    maxprofit = profit;
                }
            }
        }

        return maxprofit;
    }
};

//optimal approach
// "While traversing, keep the cheapest buying price I've encountered, and see how much I would make if I sold at today's price.


#include <bits/stdc++.h>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice= INT_MAX;
        int n=prices.size();
        int maxprofit=0;
        for(int i=0;i<n;i++){
            //if current price min price we will update min price 
            //because we want to reduce to reduce buying price
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            // if not then we check profit by(currentdayprice-minum price we have countred) 
            else{
               maxprofit=max(maxprofit,prices[i]-minPrice);
            }
        }

    return maxprofit;
    }
};