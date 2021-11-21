###############################################################################################
# simple recursion
###########
# Time Complexity: O(nlogn), n is the number of nodes in the tree
# Space Complexity: O(logn)
###############################################################################################
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def dfs(ino, poo):
            if not ino or not poo:
                return None
            idx = ino.index(poo[-1])
            root = TreeNode(poo[-1], None, None)
            root.left = dfs(ino[0:idx], poo[0:idx])
            root.right = dfs(ino[idx+1:], poo[idx:-1])
            return root
        return dfs(inorder, postorder)