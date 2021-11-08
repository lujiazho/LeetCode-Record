###############################################################################################
# the length of left or right subtree determines the numebr of subtree's structure
###########
# 时间复杂度：O(n^2)
# 空间复杂度：O(n)
###############################################################################################
class Solution:
    def numTrees(self, n: int) -> int:
        G = [0]*(n+1) # G[i]: the number of unique BST's for a length of i
        G[0] = G[1] = 1 # When length equals to 0 and 1, the number of type should be 1
        
        for i in range(2, n+1): # len = i
            for j in range(1, i+1): # j is root
                G[i] += G[j-1]*G[i-j] # the length determines the number of structure's type
        return G[n]