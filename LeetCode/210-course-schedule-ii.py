###############################################################################################
# use topo, each time study the course that has no prerequisites
############# 
# Time Complexity: O(len(prerequisites))
# Space Complexity: O(len(prerequisites))
###############################################################################################
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        h = [-1]*numCourses
        val = []
        nex = []
        idx = 0
        res = []
        d = [0]*numCourses # in-degree
        
        def insert(a, b):
            nonlocal idx
            val.append(b)
            nex.append(h[a])
            h[a] = idx
            idx += 1
        
        def topo():
            hh, tt = -1, 0
            for i in range(numCourses):
                if not d[i]:
                    res.append(i)
                    tt += 1
            
            while tt - hh > 1:
                hh += 1
                t = res[hh]
                i = h[t]
                while i != -1:
                    j = val[i]
                    d[j] -= 1
                    if not d[j]:
                        res.append(j)
                        tt += 1
                    i = nex[i]
            return tt == numCourses
        for a, b in prerequisites:
            insert(b, a)
            d[a] += 1
        if topo():
            return res
        return []