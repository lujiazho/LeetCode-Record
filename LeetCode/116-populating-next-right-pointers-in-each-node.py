###############################################################################################
# not hard
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        start = end = 0
        stack = [root]
        while start <= end:
            for i in range(start, end):
                if stack[i]:
                    stack[i].next = stack[i+1]
                    stack.extend([stack[i].left, stack[i].right])
            if stack[end]:
                stack.extend([stack[end].left, stack[end].right])
            start, end = end + 1, len(stack)-1
        return root


# reduce the Space Complexity
class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        stack = [root]
        while stack:
            newStack = []
            for i in range(len(stack)-1):
                if stack[i]:
                    stack[i].next = stack[i+1]
                    newStack.extend([stack[i].left, stack[i].right])
            if stack[-1]:
                newStack.extend([stack[-1].left, stack[-1].right])
            stack = newStack
        return root