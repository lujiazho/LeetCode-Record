###############################################################################################
# dfs
###########
# 时间复杂度：O(n^2)
# 空间复杂度：O(n^2)
###############################################################################################
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board), len(board[0])
        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        def dfs(i, j):
            if not (0 < i < m-1 and 0 < j < n-1):
                return 0
            ret = 1
            transed.add((i,j))
            for dx, dy in dirs:
                nx, ny = i+dx, j+dy
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] == 'O' and (nx,ny) not in transed:
                    ret &= dfs(nx, ny)
                    if not ret:
                        break
            return ret
        walked = set()
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O' and (i,j) not in walked:
                    transed = set()
                    if dfs(i, j):
                        for x, y in transed:
                            board[x][y] = 'X'
                    else:
                        walked |= transed # 优化去重，走过的不行的就不用再走了