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
    int best = 0;
    int height(TreeNode* root){
        if (!root)
            return -1;
        int lh = height(root->left);
        int rh = height(root->right);
        best = max(best,lh+rh+2); // diameter through root
        return max(lh,rh)+1; // height of root
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;
    }
};