###############################################################################################
# one traversal
###########
# 时间复杂度：O(n)，n为树上节点数
# 空间复杂度：O(L)，树深度
###############################################################################################
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        pax = pay = -1
        lx = ly = -1
        res = 0
        def dfs(pa_val, node, level):
            nonlocal lx, ly, pax, pay, res
            if node.val == x:
                pax = pa_val
                lx = level
            if node.val == y:
                pay = pa_val
                ly = level
            if lx != -1 and ly != -1:
                res = (lx == ly) and (pax != pay)
                return
            if node.left:
                dfs(node, node.left, level+1)
            if node.right:
                dfs(node, node.right, level+1)
        dfs(-1, root, 0)
        return res