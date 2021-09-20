###############################################################################################
# 傻瓜式判断即可
###########
# 时间复杂度：O(n^2), n是grid边长
# 空间复杂度：O(n^2)
###############################################################################################
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        grid = [[' ']*3 for _ in range(3)]
        
        def checkWinner():
            for i in range(3):
                A_row = B_row = 1
                A_col = B_col = 1
                for j in range(3):
                    if grid[i][j] != 'A':
                        A_row = 0
                    if grid[i][j] != 'B':
                        B_row = 0
                    if grid[j][i] != 'A':
                        A_col = 0
                    if grid[j][i] != 'B':
                        B_col = 0
                if A_row or A_col:
                    return 'A'
                if B_row or B_col:
                    return 'B'
            if grid[0][0] == 'A' and grid[1][1] == 'A' and grid[2][2] == 'A':
                return 'A'
            if grid[0][0] == 'B' and grid[1][1] == 'B' and grid[2][2] == 'B':
                return 'B'
            if grid[2][0] == 'A' and grid[1][1] == 'A' and grid[0][2] == 'A':
                return 'A'
            if grid[2][0] == 'B' and grid[1][1] == 'B' and grid[0][2] == 'B':
                return 'B'
            return 'Draw' if len(moves) == 9 else 'Pending'
        for i, (x, y) in enumerate(moves):
            if not i % 2: # A
                grid[x][y] = 'A'
            else: # B
                grid[x][y] = 'B'
        return checkWinner()