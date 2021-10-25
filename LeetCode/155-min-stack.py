###############################################################################################
# use O(n) auxiliary space
###########
# 时间复杂度：O(1)
# 空间复杂度：O(n)
###############################################################################################
class MinStack:

    def __init__(self):
        self.stack = []

    def push(self, val: int) -> None:
        cur = self.getMin()
        if cur != None and cur <= val:
            self.stack.append([val, cur])
        else:
            self.stack.append([val, val])

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        if not self.stack:
            return None
        else:
            return self.stack[-1][1]