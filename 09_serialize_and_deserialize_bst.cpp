/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }
    // int convertToInt(string s) {
    //     int num = 0;
    //     for (char ch : s)
    //         num = num * 10 + (ch-'0');
    //     return num;
    // }
    void tokenize(vector<int>& nums, string data) {
        stringstream ss(data);
        string s;
        while (getline(ss, s, '-')) {
            nums.push_back(stoi(s));
        }
    }
    void dfs(string& data, TreeNode* root) {
        if (!root) return;
        data += to_string(root->val) + "-";
        dfs(data, root->left);
        dfs(data, root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        dfs(data, root);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nums;
        tokenize(nums, data);
        // for (int i : nums) cout << i << " ";
        // cout << "\n";
        TreeNode* root = nullptr;
        for (int i : nums)
            root = insert(root, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
