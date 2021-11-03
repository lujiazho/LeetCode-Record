###############################################################################################
# 遍历一遍
###########
# 时间复杂度：O(n)
# 空间复杂度：O(logn)
###############################################################################################
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        res = 0
        def dfs(node, s):
            if not node.left and not node.right:
                nonlocal res
                res += int(s)
                return
            
            if node.left:
                dfs(node.left, s+f"{node.left.val}")
            if node.right:
                dfs(node.right, s+f"{node.right.val}")
        
        dfs(root, f"{root.val}")
        return res