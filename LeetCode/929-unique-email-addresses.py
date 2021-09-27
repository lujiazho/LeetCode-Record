###############################################################################################
# easy, check the character one by one
###########
# 时间复杂度：O(m*n), m is len of emails, n is aveLen of email
# 空间复杂度：O(m), hash map usage
###############################################################################################
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        Act = set()
        for ema in emails:
            newE = ""
            flagAT = flagPS = 0 # flagAT/PS indicates whether the @/+ has showed up
            for ch in ema:
                if ch == '@':
                    flagAT = 1
                    newE += ch
                elif flagAT:
                    newE += ch
                elif ch == '+':
                    flagPS = 1
                elif not flagPS and ch != '.':
                    newE += ch
            Act.add(newE)
        return len(Act)