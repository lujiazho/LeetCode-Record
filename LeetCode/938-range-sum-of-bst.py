###############################################################################################
# easy
############# 
# Time Complexity: O(n)
# Space Complexity: O(n), the worst is O(n)
###############################################################################################
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        def dfs(node):
            res = 0
            if low <= node.val <= high:
                res += node.val
            if node.left and node.val > low:
                res += dfs(node.left)
            if node.right and node.val < high:
                res += dfs(node.right)
            return res
        return dfs(root)