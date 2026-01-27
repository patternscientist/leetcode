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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> levels(1, vector<int>(1, root->val));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sz = q.size();
            vector<int> level;
            for (int i=0; i<(int)sz; ++i){
                TreeNode* cur = q.front(); q.pop();
                if (cur->left){
                    level.push_back(cur->left->val);
                    q.push(cur->left);
                }
                if (cur->right){ 
                    level.push_back(cur->right->val);
                    q.push(cur->right);
                }
            }

            if (!level.empty()) levels.push_back(level);
        }
        return levels;
    }
};