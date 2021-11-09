###############################################################################################
# trie + dfs
###########
# 时间复杂度：O(num_w*50 + num_p*(7^50)), num_w是words长度, num_p是puzzles长度, 最坏情况dfs是7^50
# 空间复杂度：O(26*num_w*50), 最坏开销
###############################################################################################
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        son = [[0]*26] # 动态增加，不用一次性开完
        cnt = [0] # cnt[i]表示以son[i]结尾的单词数
        idx = 1
        
        def insert(s):
            nonlocal idx
            p = 0
            for i in range(len(s)):
                id_ = ord(s[i]) - ord('a')
                if not son[p][id_]:
                    son.append([0]*26)
                    cnt.append(0)
                    son[p][id_] = idx
                    idx += 1
                p = son[p][id_]
            cnt[p] += 1
        
        def dfs(i, lis, p, flag):
            if flag:
                res[i] += cnt[p]
            for id_ in lis:
                if son[p][id_]:
                    dfs(i, lis, son[p][id_], 1 if id_ == lis[0] or flag else 0)
        
        for word in words:
            insert(word)
        
        res = [0]*len(puzzles)
        for i in range(len(puzzles)):
            dfs(i, [ord(ch) - ord('a') for ch in puzzles[i]], 0, 0)
        return res