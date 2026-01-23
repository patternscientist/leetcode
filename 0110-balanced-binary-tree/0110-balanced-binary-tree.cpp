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
    int heightOrFail(TreeNode* root){
        if (!root) return -1;
        int lh = heightOrFail(root->left);
        if (lh == -2) return -2;
        int rh = heightOrFail(root->right);
        if (rh == -2) return -2;
        if (abs(lh - rh) > 1) return -2;
        return 1 + max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return heightOrFail(root) != -2;
    }
};