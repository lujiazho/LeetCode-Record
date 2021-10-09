###############################################################################################
# 暴搜直接超时，改成trie后时间复杂度还是高
###########
# 时间复杂度：O(m*n*(3^l)), l 是最长单词的长度
# 空间复杂度：O(k*l), k是单词数，l是最长单词长度，用于存sons
###############################################################################################
class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        m, n = len(board), len(board[0])
        sons = [defaultdict(int) for _ in range(2)]
        isword = [0]*2
        idx = 1
        
        def insert(word):
            nonlocal idx
            p = 0
            for i in range(len(word)):
                id_ = ord(word[i]) - ord('a')
                if id_ not in sons[p]:
                    sons[p][id_] = idx
                    idx += 1
                    sons.append(defaultdict(int))
                    isword.append(0)
                p = sons[p][id_]
            isword[p] = 1
        
        for word in words:
            insert(word)

        dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]]
        def dfs(x, y, p, path):
            if ord(board[x][y]) - ord('a') not in sons[p]:
                return
            p = sons[p][ord(board[x][y]) - ord('a')]
            path += board[x][y]
            if isword[p]:
                res.append(path)
                isword[p] = 0 # 只加入一次
            
            for ux, uy in dirs:
                nx, ny = x+ux, y+uy
                if (nx, ny) not in st and 0 <= nx < m and 0 <= ny < n:
                    st.add((nx, ny))
                    dfs(nx, ny, p, path)
                    st.remove((nx,ny))

        res = []
        for i in range(m):
            for j in range(n):
                st = set()
                st.add((i,j))
                dfs(i, j, 0, "")
        return res