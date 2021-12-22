###############################################################################################
# add the prev attribute to each node
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        j = head
        j.prev = None
        length = 1
        while j.next:
            j.next.prev = j
            j = j.next
            length += 1
        
        i = head
        for _ in range(math.ceil(length/2)-1):
            new_i, new_j = i.next, j.prev
            j.next = i.next
            i.next.prev = j
            i.next = j
            j.prev = i
            i, j = new_i, new_j
        if length%2:
            i.next = None
        else:
            j.next = None