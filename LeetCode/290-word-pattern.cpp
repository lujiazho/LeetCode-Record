///////////////////////////////////////////////////////////////////////////////////////////////
// easy, just a little edge case
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> m;
        unordered_map<char, string> n;
        int j=0;
        for (int i=0 ; i<s.length() ; i++){
            string cur="";
            while (i<s.length() && s[i] != ' ')
                cur += s[i++];
            auto get = m.find(cur);
            if ((get != m.end() && m[cur] != pattern[j]) || (get == m.end() && n.find(pattern[j]) != n.end()))
                return false;
            if (j >= pattern.length())
                return false;
            m[cur] = pattern[j];
            n[pattern[j]] = cur;
            j += 1;
        }
        if (j != pattern.length())
            return false;
        return true;
    }
};