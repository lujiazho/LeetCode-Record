///////////////////////////////////////////////////////////////////////////////////////////////
// this is hard so I borrow other's method, which is perfect
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int h = accumulate(nums.begin(), nums.end(), 0); // allow m=1
        int l = *max_element(nums.begin(), nums.end()); // must could contain every number
        int mid;
        while (l < h){
            mid = (l+h)>>1; // expected max in each subarrays
            // if expected partition num > m
            if (get_partition_num(nums, mid) > m)
                l = mid + 1;
            else
                h = mid;
        }
        return h;
    }
    int get_partition_num(vector<int>& nums, int threshold){
        int cur = 0, ret = 0;
        for (int i=0 ; i<nums.size() ; i++){
            if (cur + nums[i] <= threshold){
                cur += nums[i];
            }else{
                ret += 1;
                cur = nums[i];
            }
        }
        return ret + 1;
    }
};