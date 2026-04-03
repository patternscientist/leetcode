class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        mp  = {}
        ans = []
        for account in accounts:
            name,rest = account[0],set(account[1:])
            if not name in mp:
                mp[name] = []
                mp[name].append(rest)
                continue
            updatedEmails = []
            toRemove = []
            allDisjoint = True
            for emails in mp[name]:
                if not rest.isdisjoint(emails):
                    updatedEmails.append(emails.union(rest))
                    toRemove.append(emails)
                    allDisjoint = False
            sz = 0
            for emails in toRemove:
                mp[name].remove(emails)
                sz += 1
            mp[name].append(reduce(lambda s,t: s.union(t),updatedEmails[1:] if sz > 1 else set(),updatedEmails[0])
                            if not allDisjoint else rest)

        for name,emailLists in mp.items():
            for emailList in emailLists:
                ans.append([name]+sorted(emailList))
        return ans

