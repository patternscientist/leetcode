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
    bool ok(TreeNode* root, long low, long high){
        if (!root) return true;
        if (!(low < root->val && root->val < high))
            return false;
        return ok(root->left,low,root->val) && ok(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return ok(root,LONG_MIN,LONG_MAX);
    }
};