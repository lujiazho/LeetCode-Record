###############################################################################################
# easy, extreme simple dfs
############# 
# Time Complexity: O(n), all nodes
# Space Complexity: O(n), the worst is n
###############################################################################################
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return 0, 0
            lSum, lTilt = dfs(node.left)
            rSum, rTilt = dfs(node.right)
            return lSum+node.val+rSum, lTilt+abs(lSum-rSum)+rTilt
        return dfs(root)[1]