###############################################################################################
# dfs典型
###########
# 时间复杂度：O((4^le)*mn), le is length of word
# 空间复杂度：O(m*n), st consumes
###############################################################################################
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        le = len(word)
        st = set()
        def dfs(x, y, i): # i represents already matched
            st.add((x,y)) # represents already walked
            if i == le-1:
                return True
            ret, dirs = 0, [[-1, 0], [0, 1], [1, 0], [0, -1]]
            for ux, uy in dirs:
                nx, ny = x+ux, y+uy
                if (nx, ny) not in st and 0 <= nx < m and 0 <= ny < n and board[nx][ny] == word[i+1]:
                    ret |= dfs(nx, ny, i+1)
                    st.remove((nx,ny))
            return ret
        for i in range(m):
            for j in range(n):
                st = set()
                if board[i][j] == word[0] and dfs(i, j, 0):
                    return True
        return False