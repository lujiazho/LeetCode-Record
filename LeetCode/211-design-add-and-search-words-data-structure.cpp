///////////////////////////////////////////////////////////////////////////////////////////////
// this problem is hard to solve by trie, it's better to compare from high bit to low bit
// Besides, we need to utilize the property of XOR, which is x^y = z <-> y = z^x
////////////////
// Time Complexity: O(31*n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        for (int i=30 ; i>=0 ; i--){
            unordered_set<int> set;
            for (int j=0 ; j<nums.size() ; j++){
                set.insert(nums[j] >> i);
            }
            res = res*2 + 1;
            int flag = 0;
            for (int j=0 ; j<nums.size() ; j++){
                auto get = set.find(res ^ (nums[j]>>i));
                if (get != set.end()){
                    flag = 1;
                    break;
                }
            }
            if (!flag) res -= 1;
        }
        return res;
    }
};