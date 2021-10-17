###############################################################################################
# 维护全局的count
###########
# 时间复杂度：O(n*L)，n为树上节点数,L为树深度
# 空间复杂度：O(L)
###############################################################################################
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        count = []
        res = 0
        
        def check():
            nonlocal res
            for per in count:
                if per == targetSum:
                    res += 1     

        def dfs(node):
            for i in range(len(count)):
                count[i] += node.val
            count.append(node.val)
            check()
            if node.left:
                dfs(node.left)
            if node.right:
                dfs(node.right)
            for i in range(len(count)):
                count[i] -= node.val
            count.pop()
        if root:
            dfs(root)
        return res

# 改count全局为局部，空间换时间
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        res = 0
        def dfs(node, count):
            nonlocal res
            for per in count:
                if per == targetSum:
                    res += 1     
            if node.left:
                dfs(node.left, [node.left.val] + [per + node.left.val for per in count])
            if node.right:
                dfs(node.right, [node.right.val] + [per + node.right.val for per in count])

        if root:
            dfs(root, [root.val])
        return res