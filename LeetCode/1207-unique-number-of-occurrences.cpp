///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> s;
        for (auto per:arr) s[per] += 1;
        unordered_set<int> st;
        for (auto per:s) {
            if (st.count(per.second) > 0) return false;
            else st.insert(per.second);
        }
        return true;
    }
};