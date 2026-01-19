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
    int treeDepth(TreeNode* root){
        if (!root) return -1;
        if (!root->left && !root->right) return 0;
        return max(1 + treeDepth(root->left),
                   1 + treeDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return true;
            
        int ld = treeDepth(root->left);
        int rd = treeDepth(root->right);

        return (isBalanced(root->left)  &&
                isBalanced(root->right) &&
                abs(ld-rd) <= 1);
    }
};