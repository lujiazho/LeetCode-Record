///////////////////////////////////////////////////////////////////////////////////////////////
// brute force
////////////////
// Time Complexity: O(n^3)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_set<string> us_is; // is palindrome
    unordered_set<string> us_not; // not palindrome
    vector<vector<string>> res;
    vector<string> partitioning; // current partition
    vector<vector<string>> partition(string s) {
        dfs(s);
        return res;
    }
    bool isPalindrome(string s){
        unordered_set<string>::const_iterator got = us_is.find(s);
        if (got != us_is.end()) return true;
        got = us_not.find(s);
        if (got != us_not.end()) return false;

        for (int i=0 ; i<s.length()/2 ; i++){
            if (s[i] != s[s.length()-i-1]){
                us_not.insert(s);
                return false;
            }
        }
        us_is.insert(s);
        return true;
    }
    void dfs(string s){
        string tmp = "";
        for (int i=0 ; i<s.length() ; i++){
            tmp += s[i];
            if (isPalindrome(tmp)){
                partitioning.push_back(tmp);
                string nex = s.substr(i+1);
                if (nex == ""){
                    res.push_back(partitioning);
                }else{
                    dfs(nex);
                }
                partitioning.pop_back();
            }
        }
    }
};
