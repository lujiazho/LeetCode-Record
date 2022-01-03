###############################################################################################
# not hard
############# 
# Time Complexity: O(max(len(trust), n))
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        inDegree = defaultdict(int) # in-degree
        outDegree = defaultdict(int) # out-degree
        for a, b in trust:
            inDegree[b] += 1
            outDegree[a] += 1
        if len(outDegree) != n-1:
            return -1 # only judge has no out-degree, every other has out-degree
        judge = 0
        for i in range(1, n+1):
            if i not in outDegree:
                judge = i
                break
        if inDegree[judge] == n - 1:
            return judge
        return -1