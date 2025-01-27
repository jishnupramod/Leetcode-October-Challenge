/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
 

Constraints:

1 <= asteroids <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/




// Not well optimized...
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> finalAst;
        int n = asteroids.size();
        for (int i=0; i<n; ++i) {
            if (asteroids[i] == -9999)
                continue;
            if (asteroids[i] < 0) {
                int j = i-1;
                while (j >= 0 and abs(asteroids[i]) > asteroids[j]) {
                    if (asteroids[j] > 0)
                        asteroids[j] = -9999;
                    --j;
                }
                if (j >= 0) {
                    if (abs(asteroids[i]) == asteroids[j]) {
                        asteroids[i] = -9999;
                        asteroids[j] = -9999;
                    } else
                        asteroids[i] = -9999;
                }
            }
        }
        for (int i : asteroids) {
            if (i != -9999)
                finalAst.push_back(i);
        }
        return finalAst;
    }
};



// Using Stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ast;
        for (int i : asteroids) {
            while (!ast.empty() and i < 0 and ast.top() > 0 and ast.top() < abs(i))
                ast.pop();
            if (!ast.empty() and i < 0 and ast.top() == abs(i)) {
                ast.pop();
                continue;
            }
            if (i > 0 or ast.empty() or ast.top() < 0)
                ast.push(i);
        }
        vector<int> finalAst;
        while (!ast.empty()) {
            finalAst.push_back(ast.top());
            ast.pop();
        }
        reverse(finalAst.begin(), finalAst.end());
        return finalAst;
    }
};




