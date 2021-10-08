###############################################################################################
# typical trie application
###########
# 时间复杂度：O(n*2000), n is number of insert, search, and startswith
# 空间复杂度：O(n*2000*26)
###############################################################################################
class Trie:

    def __init__(self):
        self.sons = [[0]*26 for _ in range(2)]
        self.cnt = [0]*2
        self.idx = 1

    def insert(self, word: str) -> None:
        p = 0
        for i in range(len(word)):
            id_ = ord(word[i]) - ord('a')
            if not self.sons[p][id_]:
                self.sons[p][id_] = self.idx
                self.idx += 1
                # dynamic increasing
                self.sons.append([0]*26)
                self.cnt.append(0)
            p = self.sons[p][id_]
        self.cnt[p] += 1

    def search(self, word: str) -> bool:
        p = 0
        for i in range(len(word)):
            id_ = ord(word[i]) - ord('a')
            if not self.sons[p][id_]:
                return False
            p = self.sons[p][id_]
        return self.cnt[p]

    def startsWith(self, prefix: str) -> bool:
        p = 0
        for i in range(len(prefix)):
            id_ = ord(prefix[i]) - ord('a')
            if not self.sons[p][id_]:
                return False
            p = self.sons[p][id_]
        return True