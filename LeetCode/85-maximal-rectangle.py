###############################################################################################
# This is not easy at all, we need two preprocessing to finish it
# 1. pre-calculate the height of 1's at a point in the matrix, where we get the [height] of rectangle
# 2. pre-calculate the left and right boundary by monotonic stack, where we get the [width] of rectangle, the boundary means the first pillar that is shorter
# There is one thing needed to notice:
# In this method, the right boundary hasn't been calculated correctly when the height is the same,
# but it not a problem, because when we come to the rightest point with the same height, 
# the right boundary will be ok again and left boundary will include correct range
# EXAMPLE:
#          
#          #
#         ##
#        ###
# ##########
# ##########
# ##########
# 0123456789
#
# In above situation, when pointing to x(0 ~ 5), the right boundary would be x + 1(1 ~ 6), which is wrong, but when it comes to x = 6
# the left boundary will be -1, the right boundary will be 10, which is perfectly right!
############# 
# Time Complexity: O(r*c)
# Space Complexity: O(r*c)
###############################################################################################
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        r = len(matrix)
        if not r:
            return 0
        c = len(matrix[0])
        
        heights = [[0]*c for _ in range(r)]
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == '1':
                    heights[i][j] = (heights[i-1][j] + 1) if i > 0 else 1
        
        res = 0
        for i in range(r):
            left, right, stack = [0]*c, [c]*c, []
            for j in range(c):
                while stack and heights[i][stack[-1]] >= heights[i][j]:
                    t = stack.pop()
                    right[t] = j # actually this is not right when height is the same, but it won't affect the final answer because it will eventually be calculated correctly when it comes to the rightest point
                left[j] = stack[-1] if stack else -1
                stack.append(j)
            
            for j in range(c):
                res = max(res, (right[j]-left[j]-1)*heights[i][j])
        return res            