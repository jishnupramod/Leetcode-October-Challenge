/*
All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.
*/




class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_map<string, bool> seqMap;
        set<string> repeatedSet;
        for (int i=0; i<=s.length()-10; ++i) {
            string substring = s.substr(i, 10);
            if (seqMap[substring])
                repeatedSet.insert(substring);
            seqMap[substring] = true;
        }
        vector<string> repeatedStrs(repeatedSet.begin(), repeatedSet.end());
        return repeatedStrs;
    }
};
