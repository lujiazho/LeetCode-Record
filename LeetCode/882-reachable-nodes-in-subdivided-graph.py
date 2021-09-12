###############################################################################################
# 此题，用了dijkstra的思想，在计算每个点的最短路的同时，记录到其所有邻边可延伸的距离min(w, maxMoves - dis)，当然可能已经超出了maxMoves，因此和0进行max
# 最后对每条这样记录的边进行计算（注意u->v和v->u双向应该是同一条边，因此要和这条边的边长取min
# 此外，还需要单独计算哪些原始点是在范围内的，利用dist即可
## 题外
# 这道题是典型的，要用最短路算法，但自己很难想到如何用这个算法来解决，即很难转化为最短路问题
###########
# 时间复杂度：O(mlogn)
# 空间复杂度：O(m)，邻接表和堆的开销
###############################################################################################
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        # 改写acwing学来的邻接表，避免一次性开特别大的空间（leetcode的空间要求高
        adjacencyList = defaultdict(dict)
        for u, v, cnt in edges:
            adjacencyList[u][v] = cnt + 1 # cnt个点，边则为cnt+1
            adjacencyList[v][u] = cnt + 1

        heap = [] # 利用heapq
        dist = [float("inf")]*n # 到原点距离
        st = [0]*n
        
        used = defaultdict(int)
        def dijkstra():
            dist[0] = 0
            heapq.heappush(heap, (0, 0)) # 两个0分别：此点当前到原点的距离和点, 以第一个排序，找离原点最近的点；这里可能会存放不同路径到同一个点
            
            while len(heap):
                dis, point = heapq.heappop(heap)
                if st[point]: # 说明此点已经走过了，且走过的那条路径是更短的，更容易到达更多的点，因此这个跳过
                    continue
                st[point] = 1
                
                for nex, w in adjacencyList[point].items():
                    used[(point, nex)] = max(min(w, maxMoves - dis), 0)
                    if dist[nex] > dis + w:
                        dist[nex] = dis + w
                        heapq.heappush(heap, (dist[nex], nex))
        
        dijkstra()
        
        res = sum([dist[i]<=maxMoves for i in range(n)]) # 统一加上原始的端点，只要到远点距离不超过maxMoves都加入
        for v, u, cnt in edges:
            res += min(cnt, used[(v,u)] + used[(u,v)]) # 这里只加中间的点
        return res

# 为了体现更纯正的dijkstra，即我们仅用寻路算法来得到每个原始点的最短路；而最后利用这个最短路，来计算所有在范围内的点，这样思路更清晰
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        # 改写acwing学来的邻接表，避免一次性开特别大的空间（leetcode的空间要求高
        adjacencyList = defaultdict(dict)
        for u, v, cnt in edges:
            adjacencyList[u][v] = cnt + 1 # cnt个点，边则为cnt+1
            adjacencyList[v][u] = cnt + 1

        heap = [] # 利用heapq
        dist = [float("inf")]*n # 到原点距离
        st = [0]*n
        
        def dijkstra():
            dist[0] = 0
            heapq.heappush(heap, (0, 0)) # 两个0分别：此点当前到原点的距离和点, 以第一个排序，找离原点最近的点；这里可能会存放不同路径到同一个点
            
            while len(heap):
                dis, point = heapq.heappop(heap)
                if st[point]: # 说明此点已经走过了，且走过的那条路径是更短的，更容易到达更多的点，因此这个跳过
                    continue
                st[point] = 1
                
                for nex, w in adjacencyList[point].items():
                    if dist[nex] > dis + w:
                        dist[nex] = dis + w
                        heapq.heappush(heap, (dist[nex], nex))
        
        dijkstra()
        
        res = sum([dist[i]<=maxMoves for i in range(n)]) # 统一加上原始的端点，只要到远点距离不超过maxMoves都加入
        for v, u, cnt in edges:
            if dist[v] <= maxMoves and dist[u] <= maxMoves:
                res += min(cnt, maxMoves - dist[v] + maxMoves - dist[u]) # 可能整条边都在范围内，也可能只有两边端点的一部分，取小的那个就行
            elif (dist[v] <= maxMoves and dist[u] > maxMoves) or (dist[v] > maxMoves and dist[u] <= maxMoves):
                res += max(maxMoves - dist[v], maxMoves - dist[u]) # 一个负一个正，取正的那个
                
        return res