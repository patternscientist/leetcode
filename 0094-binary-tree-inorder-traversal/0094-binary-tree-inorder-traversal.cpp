/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> dfs(TreeNode* root, vector<int>& v){
        if (!root) return v;
        vector<int> left = dfs(root->left,v);
        left.push_back(root->val);
        return dfs(root->right,left);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v{};
        return dfs(root,v);
    }
};