###############################################################################################
# a little bit complex becasue of various edge case
###########
# Time Complexity: O(logn)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        def find(node, fa):
            if node.val == key:
                return node, fa
            l = r = None
            fl = fr = None
            if node.left:
                l, fl = find(node.left, node)
            if node.right:
                r, fr = find(node.right, node)
            if l:
                return l, fl
            if r:
                return r, fr
            return None, None
        def findsub(node, fa, flag): # flag 0 : find max in left, 1 : find min in right
            if node.right if not flag else node.left:
                return findsub(node.right if not flag else node.left, node, flag)
            return node, fa, flag
        t, ft = find(root, None) if root else (None, None)
        flag = -1
        if t:
            if t.right:
                s, f, flag = findsub(t.right, t, 1)
            elif t.left:
                s, f, flag = findsub(t.left, t, 0)
            else:
                if ft:
                    if ft.left and ft.left.val == t.val:
                        ft.left = None
                    else:
                        ft.right = None
                else:
                    return None
                return root
        else:
            return root
        x = s.val
        if f.val != t.val:
            if flag:
                f.left = f.left.right
            else:
                f.right = f.right.left
        else:
            if flag:
                f.right = f.right.right
            else:
                f.left = f.left.left
        t.val = x
        return root