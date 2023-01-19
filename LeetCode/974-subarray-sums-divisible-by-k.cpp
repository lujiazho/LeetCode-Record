///////////////////////////////////////////////////////////////////////////////////////////////
// math
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int negMod(int n,int mod){
        if(n < 0){
            n=abs(n)%mod;
            return (-n+mod)%mod;
        }
        return n%mod;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0, ans = 0;
        // m[k]: how many times have the mod-equal-to-k occured previously
        // when get the same mod result, means there must be a divisible sum by k in middle
        unordered_map<int,int> m;
        m[0]++;
        
        for(int num:nums){
            cur = (cur + negMod(num, k)) % k;
            if(m.count(cur)) ans += m[cur];
            m[cur] ++;
        }
        return ans;
    }
};