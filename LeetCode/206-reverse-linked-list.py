###############################################################################################
# 双指针实现，这个是i指向第一个，j指向第二个节点
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        i = head
        if head:
            j = head.next
            i.next = None # 免得成环
        else:
            return head
        while j:
            tmp = j.next
            j.next = i
            i, j = j, tmp
        return i

# 单指针：只需要开一个参数，head作为后面那个指针；这是prev指向None，head指向第一个节点
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        while head:
            tmp = head.next
            head.next = prev
            prev, head = head, tmp
        return prev

###############################################################################################
# 递归实现
###########
# 时间复杂度：O(n)
# 空间复杂度：O(logn)
###############################################################################################
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def dps(prev, x):
            if x:
                tmp = x.next
                x.next = prev
                prev = dps(x, tmp)
            return prev
        return dps(None, head)