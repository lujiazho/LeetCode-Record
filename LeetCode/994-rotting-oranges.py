###############################################################################################
# 暴搜完事
###########
# 时间复杂度：O((n^2)*(2^20)), 最坏的，实际上远达不到
# 空间复杂度：O(n^2)
###############################################################################################
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        times, m, n = defaultdict(int), len(grid), len(grid[0])
        rotten = set()
        def dfs(i, j, t):
            times[(i,j)] = min(times[(i,j)], t) if (i,j) in times else t
            
            dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            for dx, dy in dirs:
                nx, ny = i+dx, j+dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 1 and (nx,ny) not in rotten:
                    rotten.add((nx,ny))
                    dfs(nx, ny, t+1)
                    rotten.remove((nx,ny))
        
        have = 0
        for i in range(m):
            for j in range(n):
                if (i-1 < 0 or not grid[i-1][j]) and (j+1 >= n or not grid[i][j+1]) and (i+1 >= m or not grid[i+1][j]) and (j-1 < 0 or not grid[i][j-1]) and grid[i][j] == 1:
                    return -1
                if grid[i][j] == 2:
                    rotten = set()
                    rotten.add((i,j))
                    dfs(i, j, 0)
                if grid[i][j]:
                    have += 1
        return -1 if len(times.values()) != have else (max(times.values()) if times.values() else 0)