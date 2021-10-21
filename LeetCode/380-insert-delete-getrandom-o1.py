###############################################################################################
# easy
###########
# 时间复杂度：O(1)
# 空间复杂度：O(n)
###############################################################################################
class RandomizedSet:

    def __init__(self):
        self.hash, self.list = {}, []

    def insert(self, val: int) -> bool:
        if val not in self.hash:
            self.list.append(val)
            self.hash[val] = len(self.list) - 1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val not in self.hash:
            return False
        lo, last = self.hash[val], self.list[-1]
        self.list[lo] = last
        self.hash[last] = lo
        self.list.pop()
        self.hash.pop(val)
        return True

    def getRandom(self) -> int:
        return self.list[random.randint(0, len(self.list)-1)]
