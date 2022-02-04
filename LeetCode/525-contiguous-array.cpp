///////////////////////////////////////////////////////////////////////////////////////////////
// not so easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero_one[nums.size()+1];
        zero_one[0] = 0;
        zero_one[1] = nums[0]==1?1:-1;
        unordered_map<int, int> m;
        m.insert(pair<int,int>(0,0));
        m.insert(pair<int,int>(zero_one[1],1));
        for (int i=2 ; i<nums.size()+1 ; i++){
            zero_one[i] = zero_one[i-1] + (nums[i-1]==1?1:-1);
            auto get = m.find(zero_one[i]);
            if (get == m.end()) m[zero_one[i]] = i; // store the loc
        }
        int res = 0;
        for (int i=1 ; i<nums.size()+1 ; i++){
            res = max(res, i - m[zero_one[i]]);
        }
        return res;
    }
};
