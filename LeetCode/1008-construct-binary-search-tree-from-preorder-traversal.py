###############################################################################################
# this tree is binary search tree, so we can use binary search to divide it
###########
# 时间复杂度：O(nlogn)
# 空间复杂度：O(n), 递归深度最差为n, 因为每次找了一个root, 可能n个都连着
###############################################################################################
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
        n = len(preorder)
        def recursion(i, right):
            l, r = i, right
            while l < r:
                mid = (l+r+1)>>1
                if preorder[mid] <= preorder[i]:
                    l = mid
                else:
                    r = mid - 1
            root = TreeNode(preorder[i])
            if i+1 <= l:
                root.left = recursion(i+1, l)
            if l+1 <= right:
                root.right = recursion(l+1, right)
            return root
        return recursion(0, n-1)