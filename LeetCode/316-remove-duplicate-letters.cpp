///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        unordered_map<char,int> in_v;
        for (int i=0 ; i<s.length() ; i++) m[s[i]] += 1;
        vector<char> v;
        for (int i=0 ; i<s.length() ; i++){
            while (v.size() && v.back() >= s[i] && m[v.back()] && !in_v[s[i]]){
                in_v[v.back()] = 0;
                v.pop_back();
            }
            if (!in_v[s[i]]){
                v.push_back(s[i]);
                in_v[s[i]] = 1;
            }
            m[s[i]] -= 1;
        }
        string res = "";
        for (int i=0 ; i<v.size() ; i++) res += v[i];
        return res;
    }
};