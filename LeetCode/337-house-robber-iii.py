###############################################################################################
# this is too silly, need optimization
############# 
# Time Complexity: O(>10^13), this is too much
# Space Complexity: O(log_2(10^4))
###############################################################################################
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # flag: 1 reps this node is robbed, 0 reps not; money means the maxmium money before considering this node
        def dfs(node, flag, money):
            if not node:
                return money
            ret = money
            if flag:
                ret = max(dfs(node.left, 0, money+node.val), money)
                ret = max(dfs(node.right, 0, ret), ret)
            else:
                # still don't rob
                ret1 = max(dfs(node.left, 0, money), money)
                ret1 = max(dfs(node.right, 0, ret1), ret1)
                # rob
                ret2 = max(dfs(node.left, 1, money), money)
                ret2 = max(dfs(node.right, 1, ret2), ret2)
                # rob one side
                ret3 = max(dfs(node.left, 0, money), money)
                ret3 = max(dfs(node.right, 1, ret3), ret3)
                ret4 = max(dfs(node.left, 1, money), money)
                ret4 = max(dfs(node.right, 0, ret4), ret4)
                ret = max(ret1, ret2, ret3, ret4)
            return ret
        return max(dfs(root, 1, 0), dfs(root, 0, 0))

# this is much better, but it still didn't pass the [time limit]
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # flag: 1 reps this node is robbed, 0 reps not; money means the maxmium money before considering this node
        def dfs(node, flag, money):
            if not node:
                return money
            ret = money
            if flag:
                ret = max(dfs(node.left, 0, money+node.val), money)
                ret = max(dfs(node.right, 0, ret), ret)
            else:
                # rob or not rob
                ret1 = max(dfs(node.left, 0, money), money)
                ret1 = max(dfs(node.left, 1, money), ret1)
                ret2 = max(dfs(node.right, 0, money), money)
                ret2 = max(dfs(node.right, 1, money), ret2)
                ret = ret1 + ret2 - money
            return ret
        return max(dfs(root, 1, 0), dfs(root, 0, 0))

# i cannot believe it still exceeds time limit; but then i found it didn't reduce the number of recursion because it will still be run two times
# because i enter two time of root, so i need to fix it
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # flag: 1 reps this node is robbed, 0 reps not; money means the maxmium money before considering this node
        def dfs(node, flag, money):
            if not node:
                return money
            ret = money
            ret1 = max(dfs(node.left, 0, money+node.val), money)
            ret2 = max(dfs(node.right, 0, money+node.val), money)
            if flag:
                ret = ret1 + ret2 - money - node.val
            else:
                # rob or not rob
                ret1 = ret1 - node.val
                ret1 = max(dfs(node.left, 1, money), ret1)
                ret2 = ret2 - node.val
                ret2 = max(dfs(node.right, 1, money), ret2)
                ret = ret1 + ret2 - money
            return ret
        return max(dfs(root, 1, 0), dfs(root, 0, 0))

# yes my mind is limited, this is super easy according to other's ans on leetcode
# this directly combine two answer into one return; and we don't need to pass current money into next level, wow
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # flag: 1 reps this node is robbed, 0 reps not; money means the maxmium money before considering this node
        def dfs(node):
            if not node:
                return (0, 0)
            left = dfs(node.left)
            right = dfs(node.right)
            return (max(left)+max(right), left[0]+right[0]+node.val)
        return max(dfs(root)) # two returns: 1 reps rob this node, 0 reps not rob
    
    
# this really teach me something:
# 1 I should make dfs as easy as possible, the best is not pass any parameter, making its function easy, such as this problem: rob
# 2 because i pass 0 and 1 to differentiate the rob and not rob, making my dfs much more complex, so I cannot cache it or store it in class
# 3 and I don't need to pass current money into next level, this could make dfs easier
# 4 just make dfs return two parameters, the first reps when not robbed, the second reps when robbed
