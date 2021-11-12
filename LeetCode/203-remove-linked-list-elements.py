###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        k, pre = head, None
        while k:
            if k.val == val:
                if pre:
                    pre.next = k.next
                else:
                    head = k.next
            else:
                pre = k
            k = k.next
        return head