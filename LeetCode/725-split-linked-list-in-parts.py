###############################################################################################
# two traversal
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        if not head:
            return [None for _ in range(k)]
        le = 1
        i = head
        while i.next:
            le += 1
            i = i.next
        sle = le//k
        res = []
        idx = head
        for i in range(k):
            j = ListNode()
            cur = j
            for _ in range(sle+1 if i<le%k else sle):
                cur.next = ListNode(idx.val, idx.next)
                idx = idx.next
                cur = cur.next
            cur.next = None
            res.append(j.next)
        return res