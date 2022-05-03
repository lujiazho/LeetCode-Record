///////////////////////////////////////////////////////////////////////////////////////////////
// reference others
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        
        int start = 0, end = v.size() - 1;
        while (start < v.size() && nums[start] == v[start]) {
            start++;
        }
        while (end >= start && nums[end] == v[end]) {
            end--;
        }
        return end - start + 1;
    }
};