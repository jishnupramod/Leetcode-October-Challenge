/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
a <= b
b - a == k
 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
Example 4:

Input: nums = [1,2,4,4,3,3,0,9,2,3], k = 3
Output: 2
Example 5:

Input: nums = [-1,-2,-3], k = 1
Output: 2
 

Constraints:

1 <= nums.length <= 10^4
-10^7 <= nums[i] <= 10^7
0 <= k <= 10^7
*/



// Using map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, pair<bool, bool>> mp; // Map to check the presence of a number and to check whether an element is used or not.
        unordered_map<int, int> cnts; // To count the occurence of each element
        for (int i : nums) {
            mp[i] = {true, false};
            ++cnts[i];
        }
        if (k == 0) { 
            int sum = 0;
            for (auto it=cnts.begin(); it!=cnts.end(); ++it) {
                if (it->second > 1 and !mp[it->first].second) {
                    sum += 1;
                    mp[it->first].second = true;
                }
            }
            return sum;
        }
        int cnt = 0;
        for (int i : nums) {
            if (mp[i-k].first and !mp[i].second) {
                ++cnt;
                mp[i].second = true;
            }
        }
        return cnt;
    }
};
