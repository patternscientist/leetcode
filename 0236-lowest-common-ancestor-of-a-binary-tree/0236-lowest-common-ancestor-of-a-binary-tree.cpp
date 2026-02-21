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
    bool hasBoth(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return false;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool sawP = false, sawQ = false;
        TreeNode* cur;
        while (!nodeQueue.empty()){
            cur = nodeQueue.front(); nodeQueue.pop();
            if (cur == p)
                sawP = true;
            else if (cur == q)
                sawQ = true;
            if (sawP && sawQ)
                return true;
            if (cur->left)
                nodeQueue.push(cur->left);
            if (cur->right)
                nodeQueue.push(cur->right);
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur){
            cout << "cur in LCA loop: " << cur->val << endl;
            cout << "left hasBoth?: \n\n" << hasBoth(cur->left,p,q) << endl;
            cout << "right hasBoth?: \n\n" << hasBoth(cur->right,p,q) << endl;
            if (hasBoth(cur->left,p,q))
                cur = cur->left;
            else if (hasBoth(cur->right,p,q))
                cur = cur->right;
            else
                return cur;
        }
        return nullptr;
    }
};