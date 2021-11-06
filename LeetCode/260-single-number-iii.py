###############################################################################################
# heap optimization
###########
# 时间复杂度：O(nlogn)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        size = len(nums)
        def down(x):
            t = x
            if 2*x < size and nums[x*2] < nums[t]:
                t = 2*x
            if 2*x+1 < size and nums[2*x+1] < nums[t]:
                t = 2*x+1
            if t - x:
                nums[t], nums[x] = nums[x], nums[t]
                down(t)
        
        for i in range(size//2-1, -1, -1):
            down(i)
        res = []
        for i in range(size):
            if nums[0] not in res:
                res.append(nums[0])
            else:
                res.remove(nums[0])
            nums[0], nums[size-1] = nums[size-1], nums[0]
            size -= 1
            down(0)
        return res

###############################################################################################
# math
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        xor = 0
        for i in range(len(nums)):
            xor ^= nums[i]
        lowestSetBit = xor ^ (xor&(xor-1)) # 最小的1，那个1只有a或b其中一个有
        zor = 0
        for i in range(len(nums)):
            if lowestSetBit & nums[i]: # 提出所有含有lowestSetBit的那个，然后全部异或起来，这样就得到要么b要么a
                zor ^= nums[i]
        return [zor, zor^xor]