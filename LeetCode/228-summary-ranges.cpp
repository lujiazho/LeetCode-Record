///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if (nums.size() == 0) return v;
        int first = nums[0];
        int cur = nums[0];
        int last = nums[0];
        for (int i=1 ; i<nums.size() ; i++){
            cur = nums[i];
            if (cur == last + 1){
                last += 1;
            }else{
                if (first != last) v.push_back(to_string(first)+"->"+to_string(last));
                else v.push_back(to_string(first));
                first = cur;
                last = cur;
            }
        }
        if (first != last) v.push_back(to_string(first)+"->"+to_string(last));
        else v.push_back(to_string(first));
        return v;
    }
};