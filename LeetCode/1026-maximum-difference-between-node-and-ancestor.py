###############################################################################################
# not hard
############# 
# Time Complexity: O(n)
# Space Complexity: O(n), this is for worst
###############################################################################################
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        res = 0
        @cache
        def dfs(node):
            nonlocal res
            if not node:
                return None, None # max, min
            l_max, l_min = dfs(node.left)
            r_max, r_min = dfs(node.right)
            max_ = min_ = node.val
            if l_max != None:
                max_ = max(max_, l_max)
            if r_max != None:
                max_ = max(max_, r_max)
            if l_min != None:
                min_ = min(min_, l_min)
            if r_min != None:
                min_ = min(min_, r_min)
            res = max(res, abs(node.val - max_), abs(node.val - min_))
            return max_, min_
        dfs(root)
        return res