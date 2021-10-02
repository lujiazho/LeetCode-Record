###############################################################################################
# 深搜超时
###########
# 时间复杂度：O(C^200_400), 400里面选200个走右或是下,即(400!)/(200!*200!)
# 空间复杂度：O(log400)
###############################################################################################
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        tx, ty = len(dungeon)-1, len(dungeon[0])-1
        def dfs(x, y, h, h_min):
            if x == tx and y == ty:
                return h_min # 返回沿路上最小的健康值，也就是初始健康值的limit
            ret = float("-inf")
            if x < tx:
                ret = max(ret, dfs(x+1, y, h+dungeon[x+1][y], min(h_min, h+dungeon[x+1][y])))
            if y < ty:
                ret = max(ret, dfs(x, y+1, h+dungeon[x][y+1], min(h_min, h+dungeon[x][y+1])))
            return ret # 返回所有可能中最大的，也就是我们至少需要的血量
        min_ = dfs(0, 0, dungeon[0][0], dungeon[0][0]) # 最优路径中沿路最低血量
        return 1-min_ if min_ < 0 else 1 # 当沿途最低血量大于0，说明初始血量为1就够了

# 加了个优化，还是超时
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        tx, ty = len(dungeon)-1, len(dungeon[0])-1
        st = defaultdict(list) # 记录走过的地方的h_min值，如果到同一个地方不同路径的h_min更小，则没必要继续搜索
        def dfs(x, y, h, h_min):
            if x == tx and y == ty:
                return h_min
            if (x,y) in st and st[(x,y)][0] > h and st[(x,y)][1] > h_min: # 优化: 只有当h和h_min都大于才更好（这是两个条件限制最优路径
                return float("-inf")
            st[(x,y)] = [h, h_min]
            ret = float("-inf")
            if x < tx:
                ret = max(ret, dfs(x+1, y, h+dungeon[x+1][y], min(h_min, h+dungeon[x+1][y])))
            if y < ty:
                ret = max(ret, dfs(x, y+1, h+dungeon[x][y+1], min(h_min, h+dungeon[x][y+1])))
            return ret
        min_ = dfs(0, 0, dungeon[0][0], dungeon[0][0])
        return 1-min_ if min_ < 0 else 1

# dfs递归改装动规，还需要多多练习啊
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        tx, ty = len(dungeon)-1, len(dungeon[0])-1
        dp = [[0]*(ty+1) for _ in range(tx+1)] # dp[i][j]: 从i,j到终点所有路径的最大沿路最小值
        
        for i in range(tx, -1, -1):
            for j in range(ty, -1, -1):
                max_ = float("-inf")
                if i < tx:
                    max_ = max(max_, dp[i+1][j])
                if j < ty:
                    max_ = max(max_, dp[i][j+1])
                dp[i][j] = min(dungeon[i][j], max_ + dungeon[i][j]) if max_ != float("-inf") else dungeon[i][j]
        return 1-dp[0][0] if dp[0][0] < 0 else 1 # 当沿途最低血量大于0，说明初始血量为1就够了

# 减少一个维度
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        tx, ty = len(dungeon)-1, len(dungeon[0])-1
        dp = [0]*(ty+1)
        for i in range(tx, -1, -1):
            newdp = [0]*(ty+1)
            for j in range(ty, -1, -1):
                max_ = float("-inf")
                if i < tx:
                    max_ = max(max_, dp[j])
                if j < ty:
                    max_ = max(max_, newdp[j+1])
                newdp[j] = min(dungeon[i][j], max_ + dungeon[i][j]) if max_ != float("-inf") else dungeon[i][j]
            dp = newdp
        return 1-dp[0] if dp[0] < 0 else 1 # 当沿途最低血量大于0，说明初始血量为1就够了