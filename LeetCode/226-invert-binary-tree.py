###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(logn)
###############################################################################################
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node):
            if not node:
                return
            node.left, node.right = node.right, node.left
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return root