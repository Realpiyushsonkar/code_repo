#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int ind) {
        if (ind < 0) return 0;
        if (ind == 0) return nums[0];

        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(nums, dp, ind - 2);
        int not_pick = solve(nums, dp, ind - 1);

        return dp[ind] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, n - 1);
    }
};