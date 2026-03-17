#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + helper(nums, index - 2, dp);
        int not_pick = helper(nums, index - 1, dp);

        return dp[index] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> temp1, temp2;

        for (int i = 1; i < nums.size(); i++) {
            temp1.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        int ans1 = helper(temp1, temp1.size() - 1, dp1);
        int ans2 = helper(temp2, temp2.size() - 1, dp2);

        return max(ans1, ans2);
    }
};