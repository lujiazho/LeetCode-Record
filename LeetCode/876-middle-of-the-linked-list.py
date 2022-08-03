###############################################################################################
# easy
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        m_num = 1
        m_node = head
        length = 1
        while head.next:
            head = head.next
            length += 1
            shouldBe = ceil((length + 1) / 2)
            while shouldBe - m_num:
                m_num += 1
                m_node = m_node.next
        return m_node
    
# i don't know how i figure above solution out, but it could be improved by fast and slow pointer
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        while (fast and fast.next):
            slow = slow.next
            fast = fast.next.next
        return slow
