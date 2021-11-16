###############################################################################################
# this is just bfs + heap, but exceed time limit
###########
# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
###############################################################################################
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        heap = []
        heapq.heappush(heap, (1, 1, 1))
        res = []
        walked = set()
        walked.add((1,1))
        while heap:
            val, i, j = heapq.heappop(heap)
            res.append(val)
            if len(res) == k:
                break
            if i + 1 <= m and (i+1, j) not in walked:
                heapq.heappush(heap, ((i+1)*(j), i+1, j))
                walked.add((i+1, j))
            if j + 1 <= n and (i, j+1) not in walked:
                heapq.heappush(heap, ((i)*(j+1), i, j+1))
                walked.add((i, j+1))
        return res[-1]


###############################################################################################
# this method is brilliant, utilize binary search and a trick to quickly calculate the number of numbers that are smaller than a certain number
###########
# Time Complexity: O(nlogn)
# Space Complexity: O(1)
###############################################################################################
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        l, r = 1, m*n
        while l < r:
            mid, count = (l+r)>>1, 0 # count is number of numbers who is smaller than mid
            for i in range(1, n+1):
                count += mid//i if mid//i<m else m # here we add thhe number of 'mid' into count 
            if count < k:
                l = mid + 1
            else:
                r = mid
        return l