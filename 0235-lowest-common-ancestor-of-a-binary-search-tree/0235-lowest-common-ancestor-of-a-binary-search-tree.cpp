/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rootVal = root->val, pVal = p->val, qVal = q->val;
        int l = min(pVal, qVal), r = max(pVal, qVal);
        // rootVal is either within, above, or below the interval [l, r]:
        if (rootVal >= l && rootVal <= r) // within
            return root;
        else if (rootVal > l && rootVal > r) // above
            return lowestCommonAncestor(root->left, p, q);
        else // below
            return lowestCommonAncestor(root->right, p, q);
        return nullptr; // shouldn't be possible to reach here
    }
};