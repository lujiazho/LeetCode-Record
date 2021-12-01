###############################################################################################
# easy dp
############# 
# Time Complexity: O(n)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def rob(self, nums: List[int]) -> int:
        # money[i][0]: the maximum money without robbing ith house
        # money[i][1]: the maximum money with robbing ith house
        money = [[0, 0] for _ in range(len(nums))]
        money[0][1] = nums[0]
        for i in range(1, len(nums)):
            money[i][0] = max(money[i-1][0], money[i-1][1])
            money[i][1] = money[i-1][0] + nums[i]
        return max(money[-1][0], money[-1][1])


# reduce space consumption
class Solution:
    def rob(self, nums: List[int]) -> int:
        money = [0, nums[0]]
        for i in range(1, len(nums)):
            newMoney = [0, 0]
            newMoney[0] = max(money[0], money[1])
            newMoney[1] = money[0] + nums[i]
            money = newMoney
        return max(money[0], money[1])

# another difinition
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        money = [0]*len(nums) # money[i]: the maximum money after considering ith house(considering means robbing or not robbing)
        money[0], money[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, len(nums)):
            money[i] = max(money[i-2]+nums[i], money[i-1])
        return money[-1]