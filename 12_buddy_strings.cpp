/*
Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.
Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which results in "ba" != B.
Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal to B.
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Constraints:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist of lowercase letters.
*/



class Solution {
public:
    bool buddyStrings(string A, string B) {
        int alen = A.length(), blen = B.length();
        if (alen != blen) return false;
        int changes = 0;
        char c1a, c2a, c1b, c2b;
        for (int i=0; i<alen; ++i) {
            if (A[i] != B[i]) {
                ++changes;
                if (changes > 2) return false;
                if (changes == 1) {
                    c1a = A[i];
                    c1b = B[i];
                } else {
                    c2a = A[i];
                    c2b = B[i];
                }
            }
        }
        if (changes == 2) {
            if (c1a == c2b and c2a == c1b) return true;
            return false;
        }
        if (changes == 0) {
            unordered_map<char, int> amap, bmap;
            for (char ch : A) ++amap[ch];
            for (char ch : B) ++bmap[ch];
            for (auto it=amap.begin(); it!=amap.end(); ++it) {
                if (it->second >= 2 and bmap[it->first] >= 2) return true;
            }
        }
        return false;
    }
};
