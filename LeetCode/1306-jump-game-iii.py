###############################################################################################
# easy
############# 
# Time Complexity: O(n)
# Space Complexity: O(n), the worst is n
###############################################################################################
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        def dfs(idx):
            if idx < 0 or idx >= len(arr):
                return False
            if arr[idx] < 0: # avoid walked more than once
                return False
            arr[idx] = -abs(arr[idx]) # flag it as 'walked' by make it negtive
            if not arr[idx]:
                return True
            res = 0
            res |= dfs(idx+abs(arr[idx]))
            if res: # optimization 1
                return res
            res |= dfs(idx-abs(arr[idx]))
            return res
        
        return dfs(start)