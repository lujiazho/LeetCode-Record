///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        vector<char> v;
        for (int i=0 ; i<s.size() ; i++){
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') v.push_back(s[i]);
            else if(!v.size() || v[v.size()-1]!=m[s[i]]) return false;
            else v.pop_back();
        }
        if (!v.size()) return true;
        return false;
    }
};