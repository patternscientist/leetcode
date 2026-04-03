class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        mp  = {}
        ans = []
        for account in accounts:
            name,rest = account[0],set(account[1:])
            #print('cur:',account)
            if not name in mp:
                mp[name] = []
                mp[name].append(rest)
                continue
            updatedEmails = []
            toRemove = []
            for emails in mp[name]:
                #print('emails:',emails)
                if not rest.isdisjoint(emails):
                    updatedEmails.append(emails.union(rest))
                    toRemove.append(emails)
            for emails in toRemove:
                mp[name].remove(emails)
            n = len(updatedEmails)
            if n == 0:
                mp[name].append(rest)
            elif n == 1:
                mp[name].append(updatedEmails[0])
            else:
                #print('UE:',updatedEmails)
                reduced = reduce(lambda s,t: s.union(t),updatedEmails,set())
                #print('reduced:',reduced)
                mp[name].append(reduced)
            #print('mp:',mp)
        #print('mp:',mp)
        for name,emailLists in mp.items():
            for emailList in emailLists:
                ans.append([name]+sorted(emailList))
        return ans

