///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int N = nums.size();
        for (int i=0 ; i<nums.size() ; i++){
            m[nums[i]] += 1;
            if (m[nums[i]] > N/2) return nums[i];
        }
        return -1;
    }
};