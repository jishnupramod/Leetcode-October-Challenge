/*
Given a list of intervals, remove all intervals that are covered by another interval in the list.

Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

After doing so, return the number of remaining intervals.

 

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1
Example 3:

Input: intervals = [[0,10],[5,12]]
Output: 2
Example 4:

Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
Example 5:

Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 1000
intervals[i].length == 2
0 <= intervals[i][0] < intervals[i][1] <= 10^5
All the intervals are unique.
*/



class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
        });
        int i = 0, covers = 0;
        while (i < n) {
            int j = i+1;
            while (j < n and intervals[i][0] <= intervals[j][0] and intervals[i][1] >= intervals[j][1])
                ++j;
            i = j;
            ++covers;
        }
        return covers;
    }
};


// In the inner while loop, the first element comparison can be avoided since the intervals vector is already sorted.
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
            return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1]);
        });
        int i = 0, covers = 0;
        while (i < n) {
            int j = i+1;
            while (j < n and intervals[i][1] >= intervals[j][1]) 
                ++j;
            i = j;
            ++covers;
        }
        return covers;
    }
};

