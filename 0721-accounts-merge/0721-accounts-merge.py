class Solution:
    class DSU:
        def __init__(self,n):
            self.parent = list(range(n))
            self.rank   = [0] * n
        def find(self,x):
            if self.parent[x] != x:
                self.parent[x] = self.find(self.parent[x])
            return self.parent[x]
        def unite(self,x,y):
            rootX = self.find(x)
            rootY = self.find(y)
            if rootX == rootY:
                return 
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        emailToName = {}
        emailToId = {}
        id_ = 0
        for account in accounts:
            name = account[0]
            for email in account[1:]:
                if not email in emailToName:
                    emailToName[email] = name
                emailToId[email] = id_
            id_ += 1
        
        dsu = self.DSU(id_)
        for account in accounts:
            firstEmailId = emailToId[account[1]]
            for email in account[2:]:
                dsu.unite(firstEmailId, emailToId[email])
        
        rootToEmails = {}
        for email,emailId in emailToId.items():
            root = dsu.find(emailId)
            if not root in rootToEmails:
                rootToEmails[root] = []
            rootToEmails[root].append(email)
        
        ans = []
        for root,emails in rootToEmails.items():
            emails = tuple(sorted(emails))
            merged = []
            merged.append(emailToName[emails[0]])
            merged.extend(emails)
            ans.append(merged)
        return ans