###############################################################################################
# 典型BFS
###########
# 时间复杂度：O(m*n*min(k, m*n)), theoretically, the number of all states should be: every single box in grid may have k states, as long as k < m*n
# 空间复杂度：O(m*n*min(k, m*n)), space needed by queue and st
###############################################################################################
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if m == 1 and n == 1: # 起点即终点的情况
            return 0
        
        def bfs():
            st = set()
            queue = []
            hh, tt = -1, 0
            queue.append(((0,0), k)) # localtion, eliminatable obstacles
            tt += 1
            
            directions = [[-1, 0], [0, 1], [1, 0], [0, -1]] # up, right, down, left
            steps = 0 # 记录全局的steps
            while tt - hh > 1:
                steps += 1 # 每一轮，steps + 1
                cnt = tt - hh - 1
                for _ in range(cnt): # 该轮可走的地方的数量
                    hh += 1
                    (x, y), ob = queue[hh]
                    st.add(((x, y), ob))

                    for ix, iy in directions:
                        nx, ny = x+ix, y+iy # new x, new y
                        if 0 <= nx < m and 0 <= ny < n:
                            if grid[nx][ny] and ob and ((nx, ny), ob-1) not in st:
                                    queue.append(((nx, ny), ob-1))
                                    st.add(((nx, ny), ob-1))
                                    tt += 1
                            elif not grid[nx][ny] and ((nx, ny), ob) not in st:
                                    if nx == m - 1 and ny == n - 1: # 终点不可能为障碍物，所以只需要这里判断
                                        return steps
                                    queue.append(((nx, ny), ob))
                                    st.add(((nx, ny), ob))
                                    tt += 1
            return -1
        return bfs()