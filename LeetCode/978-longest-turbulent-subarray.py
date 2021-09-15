###############################################################################################
# 一次遍历
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)，没有额外开销
###############################################################################################
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        if len(arr) < 3:
            if len(arr) == 2 and arr[0] == arr[1]:
                return 1
            return len(arr)
        pre_ = arr[1] - arr[0]
        len_ = 1 if not pre_ else 2
        res = 0
        for i in range(2, len(arr)):
            thi_ = arr[i] - arr[i-1]
            if (thi_>0 and pre_<=0) or (thi_<0 and pre_>=0):
                len_ += 1
                pre_ = thi_
            else:
                res = max(res, len_)
                len_ = 1 if not thi_ else 2
        return max(res, len_)