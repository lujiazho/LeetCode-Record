###############################################################################################
# this solution is awesome
###########
# 时间复杂度：O((logn)^2), getDepth fuction is O(logn), we need to count Nodes for left or right sub tree, which is another O(logn)
# 空间复杂度：O((logn)^2), stack consumption
###############################################################################################
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def getDepth(node):
            if not node:
                return 0
            return 1 + getDepth(node.left)
        
        if not root:
            return 0
        leftDepth = getDepth(root.left)
        rightDepth = getDepth(root.right)
        
        # left subtree is a perfect binary tree, right sub tree is a complete b tree
        if leftDepth == rightDepth:
            return 2**leftDepth + self.countNodes(root.right)
        # right sub tree is a perfect binary tree, left is a complete binary tree
        else:
            return 2**rightDepth + self.countNodes(root.left)