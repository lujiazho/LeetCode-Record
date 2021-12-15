###############################################################################################
# easy
############# 
# Time Complexity: O(n^2)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        i, pre = head.next, head
        while i:
            if i.val < pre.val:
                j, idx = head, None
                while j.val < i.val:
                    idx = j
                    j = j.next
                k = i
                pre.next = i.next
                k.next = j
                if idx:
                    idx.next = k
                else:
                    head = k
            pre = i
            i = i.next
        return head