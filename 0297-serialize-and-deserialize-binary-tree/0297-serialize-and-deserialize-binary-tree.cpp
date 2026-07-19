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
        if (!root)
            return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (cur){
                s += to_string(cur->val) + "#";
                q.push(cur->left);
                q.push(cur->right);
            } else 
                s += "n#";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        vector<string> tokens;
        string token;
        for (char ch : data){
            if (ch == '#'){
                tokens.push_back(token);
                token.clear();
            } else
                token.push_back(ch);
        }
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        int n = (int)tokens.size();
        while (i < n && !q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (i < n && tokens[i] != "n"){
                cur->left = new TreeNode(stoi(tokens[i]));
                q.push(cur->left);
            }
            i++;
            if (i < n && tokens[i] != "n"){
                cur->right = new TreeNode(stoi(tokens[i]));
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