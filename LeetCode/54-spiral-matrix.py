###############################################################################################
# 纯模拟
###########
# 时间复杂度：O(n^2)，全部遍历一遍
# 空间复杂度：O(1)，返回值不算
###############################################################################################
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        def dfs(x, y, ub, rb, db, lb, direction):
            if direction == 1: # up
                if x >= ub:
                    res.append(matrix[x][y])
                    if x == ub:
                        dfs(x, y + 1, ub, rb, db, lb+1, 2) # turn right, left boundary + 1
                    else:
                        dfs(x - 1, y, ub, rb, db, lb, 1) # go on
            elif direction == 2: # right
                if y <= rb:
                    res.append(matrix[x][y])
                    if y == rb:
                        dfs(x + 1, y, ub+1, rb, db, lb, 3) # turn down, up boundary + 1
                    else:
                        dfs(x, y + 1, ub, rb, db, lb, 2) # go on
            elif direction == 3: # down
                if x <= db:
                    res.append(matrix[x][y])
                    if x == db:
                        dfs(x, y - 1, ub, rb-1, db, lb, 4) # turn left, right boundary - 1
                    else:
                        dfs(x + 1, y, ub, rb, db, lb, 3) # go on
            elif direction == 4: # left
                if y >= lb:
                    res.append(matrix[x][y])
                    if y == lb:
                        dfs(x - 1, y, ub, rb, db-1, lb, 1) # turn up, left boundary - 1
                    else:
                        dfs(x, y - 1, ub, rb, db, lb, 4) # go on
        dfs(0, 0, 0, len(matrix[0])-1, len(matrix)-1, 0, 2)
        return res