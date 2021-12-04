###############################################################################################
# interesting, I use trie tree to store the words but in inverse order
# and every query also start from the end of streams
############# 
# Time Complexity: O(2000*2000)
# Space Complexity: O(2000*2000)
###############################################################################################
class StreamChecker:

    def __init__(self, words: List[str]):
        self.son = [[0]*26]
        self.cnt = [0]
        self.idx = 1
        for word in words:
            self.insert(word[::-1]) # make query efficiently
        self.streams = []
        
    def insert(self, word: str):
        p = 0
        for i in range(len(word)):
            id_ = ord(word[i]) - ord('a')
            if not self.son[p][id_]:
                self.son[p][id_] = self.idx
                self.son.append([0]*26)
                self.cnt.append(0)
                self.idx += 1
            p = self.son[p][id_]
        self.cnt[p] += 1

    def query(self, letter: str) -> bool:
        self.streams.append(letter)
        p = 0
        for i in range(len(self.streams)-1, -1, -1):
            id_ = ord(self.streams[i]) - ord('a')
            if not self.son[p][id_]:
                return False
            p = self.son[p][id_]
            if self.cnt[p]:
                return True
        return False