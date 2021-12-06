###############################################################################################
# easy...
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        zero_ones = [0, 0]
        for po in position:
            zero_ones[po%2] += 1
        return min(zero_ones)