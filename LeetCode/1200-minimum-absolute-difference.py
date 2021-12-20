###############################################################################################
# sort + hash
############# 
# Time Complexity: O(nlogn)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        diffs = defaultdict(list)
        for i in range(1, len(arr)):
            diffs[arr[i]-arr[i-1]].append([arr[i-1], arr[i]])
        return diffs[min(diffs.keys())]