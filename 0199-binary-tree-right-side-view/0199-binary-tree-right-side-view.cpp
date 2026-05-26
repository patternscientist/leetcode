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
        queue<TreeNode*> q;
        if (root->left){
            q.push(root->left);
        }
        vector<int> ans;
        ans.push_back(root->val);
        queue<TreeNode*> q2;
        if (root->right)
            q2.push(root->right);
        int maxRightDepth = 0;
        while (!q2.empty()){
            maxRightDepth++;
            int sz = (int)q2.size();
            for (int i=0; i<sz; i++){
                TreeNode* cur = q2.front();
                q2.pop();
                if (i == sz-1)
                    ans.push_back(cur->val);
                if (cur->left)
                    q2.push(cur->left);
                if (cur->right)
                    q2.push(cur->right);
            }
        }

        // root = root->right;
        // while (root){
        //     maxRightDepth++;
        //     ans.push_back(root->val);
        //     root = root->right;
        // }

        int leftDepth = 1;
        while (!q.empty()){
            int sz = (int)q.size();
            for (int i=0; i<sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                // cout << "cur val: " << cur->val << endl;
                // cout << "cur i: " << i << endl;
                // cout << "sz: " << sz << endl;
                if (i == sz-1 && leftDepth > maxRightDepth)
                    ans.push_back(cur->val);
                if (cur->left) 
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            leftDepth++;
        }
        return ans;
    }
};