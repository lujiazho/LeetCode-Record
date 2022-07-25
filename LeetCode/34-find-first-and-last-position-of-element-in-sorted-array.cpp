///////////////////////////////////////////////////////////////////////////////////////////////
// easy binary search
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return vector<int>{-1, -1};
        int l=0, r=nums.size()-1;
        while (l < r){
            int mid = (l+r)>>1;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] != target) return vector<int>{-1, -1};
        int left = l;
        l = 0;
        r = nums.size()-1;
        while (l < r){
            int mid = (l+r+1)>>1;
            if (nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        return vector<int>{left, l};
    }
};