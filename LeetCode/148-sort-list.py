###############################################################################################
# quick sort
###########
# Time Complexity: O(nlogn)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # quick sort
        # 3 steps:
        # 1 choose a number 'pick' in the list, such as the middle one
        # 2 put all the numbers that are smaller than pick at pick's left, put all the numbers greater than pick at pick's right side
        # 3 do the recursion on the left and right side, respectively
        if not head:
            return None
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        def quick_sort(l, r):
            if l >= r:
                return
            # step 1
            pick, i, j = nums[(l+r)>>1], l-1, r+1
            # step 2
            while i < j:
                i += 1
                while nums[i] < pick:
                    i += 1
                j -= 1
                while nums[j] > pick:
                    j -= 1
                if i < j:
                    nums[i], nums[j] = nums[j], nums[i]
            # step 3:
            quick_sort(l, j)
            quick_sort(j+1, r)
            
        quick_sort(0, len(nums)-1)

        head = ListNode()
        point = head
        for i in range(len(nums)):
            point.val = nums[i]
            if i != len(nums)-1:
                point.next = ListNode()
                point = point.next
        return head