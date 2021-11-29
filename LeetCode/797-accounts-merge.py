###############################################################################################
# dfs, easy
###########
# Time Complexity: O(n)
# Space Complexity: O(n), the worst is O(n)
###############################################################################################
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n, res = len(graph), []
        def dfs(i, path):
            if i == n - 1:
                res.append(path)
                return
            for nex in graph[i]:
                dfs(nex, path+[nex])
        dfs(0, [0])
        return res