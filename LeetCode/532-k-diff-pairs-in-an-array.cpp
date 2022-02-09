///////////////////////////////////////////////////////////////////////////////////////////////
// in c++, it's not like in Python to easily store a pair in hash set, here is a way with string
////////////////
// Time Complexity: O(n^2), worst condition
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<string> s;
        unordered_map<int, vector<int>> m;
        for (int i=0 ; i<nums.size() ; i++){
            m[nums[i]].push_back(i); // record the location
        }
        int res = 0;
        for (int i=0 ; i<nums.size() ; i++){
            auto get_l = m.find(nums[i]+k);
            auto get_g = m.find(nums[i]-k);
            string l1 = to_string(nums[i]+k)+","+to_string(nums[i]);
            string l2 = to_string(nums[i])+","+to_string(nums[i]+k);
            if (get_l != m.end() && s.find(l1) == s.end() && s.find(l2) == s.end()){
                for (int j=0 ; j<m[nums[i]+k].size() ; j++){
                    if (m[nums[i]+k][j] > i){
                        res += 1;
                        s.insert(l1);
                        s.insert(l2);
                        break;
                    }
                }
            }
            string g1 = to_string(nums[i]-k)+","+to_string(nums[i]);
            string g2 = to_string(nums[i])+","+to_string(nums[i]-k);
            if (get_g != m.end() && s.find(g1) == s.end() && s.find(g2) == s.end()){
                for (int j=0 ; j<m[nums[i]-k].size() ; j++){
                    if (m[nums[i]-k][j] > i){
                        res += 1;
                        s.insert(g1);
                        s.insert(g2);
                        break;
                    }
                }
            }
        }
        return res;
    }
};

// here is with self-made 'pair_hash'
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<pair<int, int>, pair_hash> s;
        unordered_map<int, vector<int>> m;
        for (int i=0 ; i<nums.size() ; i++){
            m[nums[i]].push_back(i); // record the location
        }
        int res = 0;
        for (int i=0 ; i<nums.size() ; i++){
            auto get_l = m.find(nums[i]+k);
            auto get_g = m.find(nums[i]-k);
            if (get_l != m.end() && s.find(pair<int,int>(nums[i],nums[i]+k)) == s.end() && s.find(pair<int,int>(nums[i]+k,nums[i])) == s.end()){
                for (int j=0 ; j<m[nums[i]+k].size() ; j++){
                    if (m[nums[i]+k][j] > i){
                        res += 1;
                        s.insert(pair<int,int>(nums[i]+k, nums[i]));
                        s.insert(pair<int,int>(nums[i], nums[i]+k));
                        break;
                    }
                }
            }
            if (get_g != m.end() && s.find(pair<int,int>(nums[i],nums[i]-k)) == s.end() && s.find(pair<int,int>(nums[i]-k,nums[i])) == s.end()){
                for (int j=0 ; j<m[nums[i]-k].size() ; j++){
                    if (m[nums[i]-k][j] > i){
                        res += 1;
                        s.insert(pair<int,int>(nums[i]-k, nums[i]));
                        s.insert(pair<int,int>(nums[i], nums[i]-k));
                        break;
                    }
                }
            }
        }
        return res;
    }
};