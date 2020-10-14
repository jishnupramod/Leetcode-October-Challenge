/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/



// Top Down DP
class Solution {
private:
    int findMax(vector<int>& nums, vector<int>& dp, int i, bool fInc) {
        if (fInc) {
            if (i >= nums.size()-1) return 0;
        }
        else {
            if (i >= nums.size()) return 0;
        }
        if (dp[i] != -1) return dp[i];
        dp[i] = max(nums[i] + findMax(nums, dp, i+2, fInc), findMax(nums, dp, i+1, fInc));
        return dp[i];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        int firstInc = findMax(nums, dp1, 0, true);
        int lastInc = findMax(nums, dp2, 1, false);
        return nums.size() == 1 ? nums[0] : max(firstInc, lastInc);
    }
};

