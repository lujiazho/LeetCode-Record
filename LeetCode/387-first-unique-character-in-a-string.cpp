///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m; // letter : <num, index>
        for (int i=0 ; i<s.size() ; i++){
            if (m.find(s[i]) == m.end())
                m[s[i]] = make_pair(1, i);
            else
                m[s[i]].first += 1;
        }
        int res = INT_MAX;
        for (auto per:m){
            if (per.second.first == 1 && per.second.second < res)
                res = per.second.second;
        }
        return res == INT_MAX?-1:res;
    }
};