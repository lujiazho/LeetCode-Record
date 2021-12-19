###############################################################################################
# use two stacks, there are something to notice, such as the letters in stack_lsb_ch is in reverse
############# 
# Time Complexity: O(n)
# Space Complexity: O(n), if not count in the space of string in the stack
###############################################################################################
class Solution:
    def decodeString(self, s: str) -> str:
        res = ""
        stack_lsb_ch = []
        stack_digit = []
        i = 0
        while i < len(s):
            ch = s[i]
            if ch.isdigit():
                digit = 0
                while ch.isdigit():
                    digit = digit*10 + int(ch)
                    i += 1
                    ch = s[i]
                stack_digit.append(digit)
                i -= 1
            elif ch == '[':
                stack_lsb_ch.append('[')
            elif ch.isalpha():
                if stack_lsb_ch:
                    stack_lsb_ch.append(ch)
                else:
                    res += ch
            else:
                digit = stack_digit.pop()
                letters = ""
                while stack_lsb_ch[-1] != '[':
                    letters += stack_lsb_ch.pop()
                stack_lsb_ch.pop() # pop the [
                if stack_lsb_ch:
                    stack_lsb_ch.append(letters*digit)
                else:
                    res += letters[::-1]*digit
            i += 1
        return res