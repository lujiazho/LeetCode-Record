###############################################################################################
# this is actually math
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if not k % 2 or not k % 5:
            return -1
        n = length = 1
        while True:
            if not n % k:
                return length
            length += 1
            n = n*10 + 1


# this is more like math, because we can prove that we only need to keep the reminder
# 10*n + 1 = 10*(kq + r) + 1 = 10*kq + 10*r + 1, where the 10*kq can definitely be divisible by k, so we only check the 10*r + 1
class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if not k % 2 or not k % 5:
            return -1
        n = length = 1
        while True:
            reminder = n % k
            if not reminder:
                return length
            length += 1
            n = reminder*10 + 1