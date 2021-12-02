###############################################################################################
# kind of interesting, use 3 pointers to traverse and re-organize linked list
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return None if not head else head
        head1, head2 = head, head.next
        i, j = head1, head2
        while j and j.next:
            i.next = j.next
            i = i.next
            j.next = i.next
            j = j.next
        i.next = head2
        return head1