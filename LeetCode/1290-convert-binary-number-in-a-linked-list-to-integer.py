###############################################################################################
# easy, when a new bit is added in the right, we only need to left shift one position, which means multiplying 2
############# 
# Time Complexity: O(n), length if linked list
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        res = 0
        while head:
            res = 2*res + head.val # or = res << 1 + head.val
            head = head.next
        return res