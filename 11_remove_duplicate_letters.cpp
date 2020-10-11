/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 10^4
s consists of lowercase English letters.
*/




// Solution using Stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> stk;
        unordered_map<char, int> chars, added;
        for (char ch : s) ++chars[ch];
        for (char ch : s) {
            while (!stk.empty() and !added[ch] and stk.back() >= ch and chars[stk.back()] > 1) {
                --chars[stk.back()];
                --added[stk.back()];
                stk.pop_back();
            }
            if (added[ch] == 0) {
                stk.push_back(ch);
                added[ch] = 1;
            } else if (added[ch] == 1)
                --chars[ch];
        }
        string res;
        for (char ch : stk)
            res += ch;
        return res;
    }
};

