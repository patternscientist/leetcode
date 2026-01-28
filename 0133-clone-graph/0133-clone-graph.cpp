/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*,Node*> mp;
        mp[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()){
            Node* v = q.front(); q.pop();
            for (Node* u : v->neighbors){
                if (!mp.count(u)){
                    mp[u] = new Node(u->val);
                    q.push(u);
                }
                mp[v]->neighbors.push_back(mp[u]);
            }
        }
        return mp[node];
    }
};