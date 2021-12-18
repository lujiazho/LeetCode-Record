###############################################################################################
# not hard, just a little bit complex because of edge case
############# 
# Time Complexity: O(lenDigits*10 + numOfDigitsOfn)
# Space Complexity: O(10)
###############################################################################################
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        res = 0
        lessThan = [0]*10 # numbers that is less than 0 - 9
        lessEqualsTo = [0]*10 # numbers that is less than or equals to 0 - 9
        lenDigits = len(digits)
        for digit in digits:
            digit = int(digit)
            for i in range(1, 10):
                lessThan[i] += 1 if digit < i else 0
                lessEqualsTo[i] += 1 if digit <= i else 0
        for i, ch in enumerate(str(n)[1:]):
            digit = int(ch)
            res += lenDigits**(len(str(n))-i-1)
        def dfs(i):
            if i >= len(str(n)):
                return 1
            ret = 0
            digit = int(str(n)[i])
            ret += lessThan[digit]*(lenDigits**(len(str(n))-i-1)) # the highest digit is less than it
            if str(digit) in digits:
                ret += dfs(i+1)
            return ret
        res += dfs(0)
        return res