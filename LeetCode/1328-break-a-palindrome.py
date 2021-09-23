###############################################################################################
# 简单，就三种情况，处理掉就行
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        if len(palindrome) == 1:
            return ""
        palindrome = list(palindrome)
        for i in range(len(palindrome)):
            if palindrome[i] != 'a' and ((not len(palindrome)%2) or i != len(palindrome)//2):
                palindrome[i] = 'a'
                return ''.join(palindrome)
        palindrome[-1] = 'b'
        return ''.join(palindrome)