///////////////////////////////////////////////////////////////////////////////////////////////
// easy but c++'s map is annoying
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i=0 ; i<nums.size() ; i++){
            m[nums[i]] += 1;
        }
        int res = 0;
        for (auto p:m){
            int num = p.first;
            int count = p.second;
            if (num*2 == k){
                res += count/2;
                m[num] = count%2;
            }else{
                while (count && m.find(k-num) != m.end() && m[k-num] > 0){
                    count--;
                    m[k-num]--;
                    res++;
                }
                m[num] = count;
            }
        }
        return res;
    }
};
