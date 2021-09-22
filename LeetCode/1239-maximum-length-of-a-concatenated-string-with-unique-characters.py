###############################################################################################
# dfs超时，因为用了大量不必要的状态
###########
# 时间复杂度：O(n^n)，n为arr的长度
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        len_ = len(arr)
        if len_ == 1:
            return len(arr[0])
        res = 0
        def dfs(l, cur):
            if l == len_:
                return
            nonlocal res
            res = max(res, len(cur))
            
            for per in arr:
                if not len(set(per) & cur):
                    dfs(l+1, cur | set(per))
        dfs(0, set())
        return res

# 加了个位运算去重，类似于剪枝
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        len_ = len(arr)
        if len_ == 1:
            return len(arr[0])
        arr = [per for per in arr if len(per) == len(set(per))] # 可能有些串内都有重复的
        res, st = 0, set()
        def getNum(x): # 通过位运算进行去重
            return sum(1 << (ord(ch) - 97) for ch in x)
        def dfs(l, cur):
            if l > len_ or getNum(cur) in st:
                return
            st.add(getNum(cur))
            nonlocal res
            res = max(res, len(cur))
            for per in arr:
                if not len(set(per) & cur):
                    dfs(l+1, cur | set(per))
        dfs(0, set())
        return res

# 换个思路：dfs还是dfs，只考虑选还是不选，因为顺序并不重要，我们不需要每个位置都遍历全部串，只需要遍历某个串可行还是不可行，有一点树形DP的感觉
# 这个时间复杂度就低了，只有O(2^n)
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        arr = [per for per in arr if len(per) == len(set(per))]
        res, len_ = 0, len(arr)
        def dfs(l, cur):
            if l == len_:
                nonlocal res
                res = max(res, len(cur))
                return
            if not len(set(arr[l]) & cur): # 没重复的就可以选
                dfs(l+1, set(arr[l]) | cur)
            dfs(l+1, cur) # 也可以不选
        dfs(0, set())
        return res

# 换成dp，空间消耗变大，因为要存dp，时间上理论上是一样的，但实际更慢，可能是因为set内置操作比人工实现getNum来比较更快
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        arr = [per for per in arr if len(per) == len(set(per))]
        res, len_ = 0, len(arr)
        if not len_:
            return 0
        dp = [set() for _ in range(len_)] # dp[i]: 前i个串，能组成的对应串
        dp[0].add(arr[0])
        dp[0].add('')
        def getNum(s):
            return sum([1 << (ord(ch) - 97) for ch in s])
        for i in range(1, len_):
            for per in dp[i-1]:
                if not getNum(arr[i]) & getNum(per): # 和前面的某串无交集
                    dp[i].add(arr[i] + per) # 则可以选
                dp[i].add(per) # 也可以不选
        return max([len(per) for per in dp[-1]])

# 现在把人工实现getNum替换成set的集合操作，稍微快一点了，但还是没递归快
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        arr = [per for per in arr if len(per) == len(set(per))]
        res, len_ = 0, len(arr)
        if not len_:
            return 0
        dp = [[] for _ in range(len_)] # dp[i]: 前i个串，能组成的对应串
        dp[0].extend([set(arr[0]), set('')])
        for i in range(1, len_):
            for per in dp[i-1]:
                if not len(set(arr[i]) & per): # 和前面的某串无交集
                    dp[i].append(set(arr[i]) | per) # 则可以选
                dp[i].append(per) # 也可以不选
        return max([len(per) for per in dp[-1]])