###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(logn)
###############################################################################################
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(node, x):
            if not node.left and not node.right and x:
                nonlocal res
                res += node.val
            if node.left:
                dfs(node.left, 1)
            if node.right:
                dfs(node.right, 0)
        dfs(root, 0)
        return res