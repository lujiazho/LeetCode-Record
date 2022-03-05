///////////////////////////////////////////////////////////////////////////////////////////////
// not easy, maybe it's because it's been a long time to do dp problem, but i finally solve it as 0/1 backpack problem
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> keys;
        for (int i=0 ; i<nums.size() ; i++){
            if (m.find(nums[i]) == m.end()) keys.push_back(nums[i]);
            m[nums[i]] += nums[i];
        }
        sort(keys.begin(), keys.end());
        vector<pair<int,int>> v;
        v.push_back(pair<int,int>(0,m[keys[0]]));
        for (int i=1 ; i<keys.size() ; i++){
            if (keys[i]-1 != keys[i-1]){
                v.push_back(pair<int,int>(max(v[i-1].first, v[i-1].second), max(v[i-1].first, v[i-1].second)+m[keys[i]]));
            }else{
                v.push_back(pair<int,int>(max(v[i-1].first, v[i-1].second), v[i-1].first+m[keys[i]]));
            }
        }
        return max(v[keys.size()-1].first, v[keys.size()-1].second);
    }
};