class Solution {
    struct DSU{
        vector<int> parent;
        vector<int> rank;
        DSU(int n){
            parent.resize(n);
            rank.assign(n,0);
            for (int i=0; i<n; i++)
                parent[i] = i;
        }
        int find(int x){
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y){
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return;
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootY] < rank[rootX])
                parent[rootX] = rootY;
            else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> emailToName;
        unordered_map<string,int> emailToId;
        int id = 0;
        for (const auto& account : accounts){
            string name = account[0];
            for (int i=1; i<(int)account.size(); i++){
                string email = account[i];
                if (!emailToName.count(email))
                    emailToName[email] = name;
                emailToId[email] = id;
            }
            id++;
        }

        DSU dsu(id);
        for (const auto& account : accounts){
            int firstEmailId = emailToId[account[1]];
            for (int i=2; i<(int)account.size(); i++){
                dsu.unite(firstEmailId, emailToId[account[i]]);
            }
        }

        unordered_map<int,vector<string>> rootToEmails;
        for (const auto& [email,emailId] : emailToId){
            int root = dsu.find(emailId);
            rootToEmails[root].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [root,emails] : rootToEmails){
            sort(emails.begin(),emails.end());
            vector<string> merged;
            merged.push_back(emailToName[emails[0]]);
            for (const string& email : emails){
                merged.push_back(email);
            }
            ans.push_back(merged);
        }
        
        return ans;
    }
};