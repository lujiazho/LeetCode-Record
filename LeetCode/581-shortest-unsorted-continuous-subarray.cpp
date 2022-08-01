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

# in O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> MIN(nums.size(), INT_MAX);
        vector<int> MAX(nums.size(), INT_MIN);
        
        int cur_min = INT_MAX, cur_max = INT_MIN;
        for (int i=0,j=nums.size()-1 ; i<nums.size(),j>=0 ; i++,j--){
            cur_max = max(cur_max, nums[i]);
            cur_min = min(cur_min, nums[j]);
            MAX[i] = cur_max;
            MIN[j] = cur_min;
        }
        int st=-1, ed=-1;
        for (int i=0,j=nums.size()-1 ; i<nums.size(),j>=0 ; i++,j--){
            if (st == -1 && MIN[i] < nums[i]) st = i;
            if (ed == -1 && MAX[j] > nums[j]) ed = j;
            if (st != -1 && ed != -1) break;
        }
        return (st==-1)?0:ed - st + 1;
    }
};
