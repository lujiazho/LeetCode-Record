###############################################################################################
# DSU, aka. union find
###########
# Time Complexity: O(n*m)
# Space Complexity: O(n*m)
###############################################################################################
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        father = defaultdict(str)
        def find(x):
            if father[x] != x:
                father[x] = find(father[x])
            return father[x]
        def union(x, y): # y is new one, x is existing union
            father[find(y)] = find(x)
        belongs = defaultdict(str)
        for account in accounts:
            name = account[0]
            if account[1] not in father:
                father[account[1]] = account[1]
                belongs[account[1]] = name
            for mail in account[2:]:
                if mail not in father:
                    father[mail] = mail
                union(account[1], mail)
        res = defaultdict(list)
        for key in father:
            res[find(key)].append(key)
        return [[belongs[key]]+sorted(res[key]) for key in res]