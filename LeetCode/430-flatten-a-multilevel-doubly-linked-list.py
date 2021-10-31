###############################################################################################
# similar to dfs
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if not head:
            return None
        def find(h, pre):
            ret = Node()
            re = ret
            while h:
                re.val = h.val
                re.prev = pre
                if h.child:
                    re.next = find(h.child, re)
                    while re.next:
                        re = re.next
                re.next = Node() if h.next else None
                re.child = None
                pre = re
                re = re.next
                h = h.next
            return ret
        return find(head, None)