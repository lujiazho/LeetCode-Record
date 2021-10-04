###############################################################################################
# easy
###########
# 时间复杂度：O(mn)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        ones = neighbors = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    ones += 1
                    if i < m - 1 and grid[i+1][j]:
                        neighbors += 1
                    if j < n - 1 and grid[i][j+1]:
                        neighbors += 1
        return ones*4 - neighbors*2