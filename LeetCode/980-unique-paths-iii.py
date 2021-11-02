###############################################################################################
# 直接暴搜竟然最好
###########
# 时间复杂度：O(3^(RC)), R = row nums, C = column nums
# 空间复杂度：O(RC)
###############################################################################################
class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        m, n = len(grid), len(grid[0])
        res = 0
        def check():
            for i in range(m):
                for j in range(n):
                    if grid[i][j] != -1 and grid[i][j] != 2:
                        return False
            return True
        def dfs(i, j):
            if grid[i][j] == 2:
                if check():
                    nonlocal res
                    res += 1
                return
            s = grid[i][j]
            grid[i][j] = -1
            
            for dx, dy in dirs:
                nx, ny = i+dx, j+dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != -1:
                    dfs(nx, ny)
            
            grid[i][j] = s
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    dfs(i, j)
                    break
        return res