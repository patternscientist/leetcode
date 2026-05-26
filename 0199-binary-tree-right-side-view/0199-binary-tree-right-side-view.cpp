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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> ans;
        ans.push_back(root->val);

        queue<TreeNode*> qRight;
        if (root->right)
            qRight.push(root->right);

        queue<TreeNode*> qLeft;
        if (root->left)
            qLeft.push(root->left);
        
        int maxRightDepth = 0;
        while (!qRight.empty()){
            maxRightDepth++;
            int sz = (int)qRight.size();
            for (int i=0; i<sz; i++){
                TreeNode* cur = qRight.front();
                qRight.pop();
                if (i == sz-1)
                    ans.push_back(cur->val);
                if (cur->left)
                    qRight.push(cur->left);
                if (cur->right)
                    qRight.push(cur->right);
            }
        }

        int leftDepth = 1;
        while (!qLeft.empty()){
            int sz = (int)qLeft.size();
            for (int i=0; i<sz; i++){
                TreeNode* cur = qLeft.front();
                qLeft.pop();
                if (i == sz-1 && leftDepth > maxRightDepth)
                    ans.push_back(cur->val);
                if (cur->left) 
                    qLeft.push(cur->left);
                if (cur->right)
                    qLeft.push(cur->right);
            }
            leftDepth++;
        }

        return ans;
    }
};