class Solution {
public:
    vector<vector<string>> partition(string s) {
        unordered_set<string> us;
        vector<vector<string>> v;
        vector<string> tmp;
        dfs(s, tmp, v, us);
        return v;
    }
    bool isPalindrome(string s, unordered_set<string> &us){
        unordered_set<string>::const_iterator got = us.find(s);
        if (got != us.end()){
            return true;
        }
        for (int i=0 ; i<s.length()/2 ; i++){
            if (s[i] != s[s.length()-i-1]){
                return false;
            }
        }
        us.insert(s);
        return true;
    }
    void dfs(string s, vector<string> &thi, vector<vector<string>> &v, unordered_set<string> &us){
        string tmp = "";
        for (int i=0 ; i<s.length() ; i++){
            tmp += s[i];
            if (isPalindrome(tmp, us)){
                thi.push_back(tmp);
                string nex = "";
                for (int j=i+1 ; j<s.length() ; j++){
                    nex += s[j];
                }
                if (nex == ""){
                    v.push_back(thi);
                }else{
                    dfs(nex, thi, v, us);
                }
                thi.pop_back();
            }
        }
    }
};