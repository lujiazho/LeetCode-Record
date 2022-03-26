///////////////////////////////////////////////////////////////////////////////////////////////
// basic binary search
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1;
        int mid = -1;
        while (start < end){
            mid = (start+end)>>1;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        return nums[end]==target?end:-1;
    }
};