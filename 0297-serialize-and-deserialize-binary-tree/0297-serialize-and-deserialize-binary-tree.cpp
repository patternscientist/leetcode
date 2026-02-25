/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while (!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if (cur){
                s += (to_string(cur->val) + "#");
                q.push(cur->left);
                q.push(cur->right);
            } else
                s += "n#";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> vals;
        string token;
        for (char ch : data){
            if (ch == '#'){
                vals.push_back(token);
                token.clear();
            } else 
                token.push_back(ch);
        }
        if (vals[0] == "n") return nullptr;
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < (int)vals.size()){
            TreeNode* cur = q.front(); q.pop();
            if (i < (int)vals.size() && vals[i] != "n"){
                cur->left = new TreeNode(stoi(vals[i]));
                q.push(cur->left);
            }
            
            i++;
            if (i < (int)vals.size() && vals[i] != "n"){
                cur->right = new TreeNode(stoi(vals[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));