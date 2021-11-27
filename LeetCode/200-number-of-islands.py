###############################################################################################
# disjoint set union
###########
# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
###############################################################################################
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        f = [[(i,j) for j in range(len(grid[0]))] for i in range(len(grid))]
        def find(lo):
            i, j = lo[0], lo[1]
            if f[i][j] != (i,j):
                f[i][j] = find(f[i][j])
            return f[i][j]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    if i-1 >= 0 and grid[i-1][j] == '1':
                        x,y = find((i,j))
                        f[x][y] = find((i-1,j))
                    if j-1 >= 0 and grid[i][j-1] == '1':
                        x,y = find((i,j))
                        f[x][y] = find((i,j-1))
                    if i+1 < len(grid) and grid[i+1][j] == '1':
                        x,y = find((i,j))
                        f[x][y] = find((i+1,j))
                    if j+1 < len(grid[0]) and grid[i][j+1] == '1':
                        x,y = find((i,j))
                        f[x][y] = find((i,j+1))
        res = set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    res.add(find((i, j)))
        return len(res)


###############################################################################################
# dfs, this is 1x faster than above
###########
# Time Complexity: O(n^2)
# Space Complexity: O(n^2), the worst is n^2, but usually we won't achieve that
###############################################################################################
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(i, j):
            grid[i][j] = '0'
            if i+1 < len(grid) and grid[i+1][j] == '1':
                dfs(i+1, j)
            if j+1 < len(grid[0]) and grid[i][j+1] == '1':
                dfs(i, j+1)
            if i-1 >= 0 and grid[i-1][j] == '1':
                dfs(i-1, j)
            if j-1 >= 0 and grid[i][j-1] == '1':
                dfs(i, j-1)
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    res += 1
                    dfs(i,j)
        return res