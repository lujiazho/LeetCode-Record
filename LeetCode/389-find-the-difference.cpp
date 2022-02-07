///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (int i=0 ; i<s.length() ; i++){
            m[s[i]] += 1;
            m[t[i]] -= 1;
        }
        m[t[t.length()-1]] -= 1;
        for (auto per:m) if (per.second) return per.first;
        return NULL;
    }
};