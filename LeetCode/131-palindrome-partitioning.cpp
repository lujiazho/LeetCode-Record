///////////////////////////////////////////////////////////////////////////////////////////////
// not so easy to solve this with c++, maybe it's because I kind of forget the STL
////////////////
// Time Complexity: O(n!)
// Space Complexity: O(C_n^1 + C_n^2 + C_n^3 + ... + C_n^n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<string>> partition(string s) {
        unordered_set<string> us_is;
        unordered_set<string> us_not;
        vector<vector<string>> v;
        vector<string> tmp;
        dfs(s, &tmp, &v, &us_is, &us_not);
        return v;
    }
    bool isPalindrome(string s, unordered_set<string> *us_is, unordered_set<string> *us_not){
        unordered_set<string>::const_iterator got = us_is->find(s);
        if (got != us_is->end()){
            return true;
        }
        got = us_not->find(s);
        if (got != us_not->end()){
            return false;
        }
        for (int i=0 ; i<s.length()/2 ; i++){
            if (s[i] != s[s.length()-i-1]){
                us_not->insert(s);
                return false;
            }
        }
        us_is->insert(s);
        return true;
    }
    void dfs(string s, vector<string> *thi, vector<vector<string>> *v, unordered_set<string> *us_is, unordered_set<string> *us_not){
        string tmp = "";
        for (int i=0 ; i<s.length() ; i++){
            tmp += s[i];
            if (isPalindrome(tmp, us_is, us_not)){
                thi->push_back(tmp);
                string nex = s.substr(i+1);
                if (nex == ""){
                    v->push_back(*thi);
                }else{
                    dfs(nex, thi, v, us_is, us_not);
                }
                thi->pop_back();
            }
        }
    }
};
