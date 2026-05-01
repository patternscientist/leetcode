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
    int best = INT_MIN;
    int dfs(TreeNode* root){
        if (!root)
            return -1;
        int lh = dfs(root->left);
        int rh = dfs(root->right);
        best = max(best,lh+rh+2);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return best;
    }
};