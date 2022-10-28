///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(100*log(100)*n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto str:strs) {
            string real = str;
            sort(real.begin(), real.end());
            m[real].push_back(str);
        }
        vector<vector<string>> res;
        for (auto per:m) {
            res.push_back(per.second);
        }
        return res;
    }
};