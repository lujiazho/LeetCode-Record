###############################################################################################
# easy
###########
# 时间复杂度：O(n)
# 空间复杂度：O(1)
###############################################################################################
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 0
        def preorder(node):
            nonlocal res
            l = r = -1
            if node.left:
                l = preorder(node.left)
            if node. right:
                r = preorder(node.right)
            res = max(res, l + r + 2)
            return 1 + max(l, r)
        preorder(root)
        return res