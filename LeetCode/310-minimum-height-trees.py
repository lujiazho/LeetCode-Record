###############################################################################################
# time limite exceeded
############# 
# Time Complexity: O(n^2)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        edges_ = defaultdict(list)
        for a, b in edges:
            edges_[a].append(b)
            edges_[b].append(a)
        
        def dfs(idx):
            if idx in walked:
                return -1
            walked.add(idx)
            ret = 0
            for nex in edges_[idx]:
                ret = max(dfs(nex)+1, ret)
            return ret
        res = []
        min_ = float("inf")
        for i in range(n):
            walked = set()
            cur = dfs(i)
            if cur == min_:
                res.append(i)
            elif cur < min_:
                min_ = cur
                res = [i]
        return res


###############################################################################################
# this method is brilliant, each iteration we delete the leaves, eventually we get the answer
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        edges_ = defaultdict(list)
        for a, b in edges:
            edges_[a].append(b)
            edges_[b].append(a)
        leaves = []
        for idx in edges_:
            if len(edges_[idx]) < 2:
                leaves.append(idx)
        while n > 2:
            newLeaves = []
            for leaf in leaves:
                edges_[edges_[leaf][0]].remove(leaf)
                if len(edges_[edges_[leaf][0]]) < 2:
                    newLeaves.append(edges_[leaf][0])
                edges_.pop(leaf)
                n -= 1
            leaves = newLeaves
        return list(edges_) if edges_ else [0]