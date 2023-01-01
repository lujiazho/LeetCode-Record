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
            // get a word in s
            string cur="";
            while (i<s.length() && s[i] != ' ')
                cur += s[i++];
            // find if it exists already
            auto get = m.find(cur);
            // if (exist and not equal) || (not exist but corresponding letter is already used)
            if ((get != m.end() && m[cur] != pattern[j]) || (get == m.end() && n.find(pattern[j]) != n.end())) return false;
            // pattern may have not enough letter
            if (j >= pattern.length()) return false;

            // record
            m[cur] = pattern[j];
            n[pattern[j]] = cur;
            j += 1;
        }
        // s may have not enough words, so j didn't reach the pattern's end
        if (j != pattern.length()) return false;
        return true;
    }
};
