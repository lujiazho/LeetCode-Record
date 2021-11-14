###############################################################################################
# I can use backtrack to get all possibilities, but here I use bitmask, which is interesting
###########
# Time Complexity: O(2^n)， n is the len of characters
# Space Complexity: O(1)
###############################################################################################
class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.comb_len = combinationLength
        self.chs = len(characters)
        self.chars = characters
        self.mask = (1 << self.chs) - 1

    def next(self) -> str:
        while self.mask > 0 and bin(self.mask).count('1') != self.comb_len:
            self.mask -= 1

        ret = ""
        for i in range(self.chs):
            if self.mask & (1 << self.chs - i - 1):
                ret += self.chars[i]
        
        self.mask -= 1
        return ret
    
    def hasNext(self) -> bool:
        while self.mask > 0 and bin(self.mask).count('1') != self.comb_len:
            self.mask -= 1
        return self.mask