###############################################################################################
# monotonic stack: at most traverse the list for two times
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        MonoStack, res = [], [0]*len(temperatures)
        for i in range(len(temperatures)-1, -1, -1):
            while MonoStack and temperatures[i] >= temperatures[MonoStack[-1]]:
                MonoStack.pop()
            if MonoStack:
                res[i] = MonoStack[-1] - i
            MonoStack.append(i)
        return res