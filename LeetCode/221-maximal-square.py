###############################################################################################
# cool, I've done this problem before
############# 
# Time Complexity: O(logn*n^2)
# Space Complexity: O(n^2)
###############################################################################################
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        areas = [[0]*(len(matrix[0])+1) for _ in range(len(matrix)+1)]
        for i in range(1, len(matrix)+1):
            for j in range(1, len(matrix[0])+1):
                areas[i][j] = int(matrix[i-1][j-1])
                if i:
                    areas[i][j] += areas[i-1][j]
                if j:
                    areas[i][j] += areas[i][j-1]
                if i and j:
                    areas[i][j] -= areas[i-1][j-1]
        min_, max_ = 0, min(len(matrix), len(matrix[0])) # the length of side
        while min_ < max_:
            mid = (min_+max_+1)>>1
            for i in range(mid, len(matrix)+1):
                for j in range(mid, len(matrix[0])+1):
                    if areas[i][j] - areas[i-mid][j] - areas[i][j-mid] + areas[i-mid][j-mid] == mid**2:
                        min_ = mid
                        break
                if min_ == mid:
                    break
            if min_ != mid:
                max_ = mid - 1
        return min_**2