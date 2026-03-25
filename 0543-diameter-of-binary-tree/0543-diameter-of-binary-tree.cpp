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
    int height(TreeNode* root){
        if (!root)
            return -1;
        if (!root->left && !root->right)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return -1;
        if (!root->left && !root->right)
            return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(max(leftHeight+rightHeight+2,left),right);
    }
};