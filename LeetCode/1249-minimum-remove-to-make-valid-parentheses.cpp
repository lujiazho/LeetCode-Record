///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        vector<int> v;
        vector<int> idx_in_res;
        int i=0;
        while (i<s.length()){
            if (97 <= s[i] && s[i] <= 122){
                res += s[i];
            }else if (s[i] == '('){
                v.push_back(i);
                res += s[i];
                idx_in_res.push_back(res.length()-1);
            }else if (s[i] == ')'){
                if (!v.empty()){
                    v.pop_back();
                    idx_in_res.pop_back();
                    res += s[i];
                }
            }
            i++;
        }
        if (!v.empty()){
            std::unordered_set<int> s(idx_in_res.begin(), idx_in_res.end());
            string new_res = "";
            for (int i=0 ; i<res.length() ; i++){
                if (s.find(i) == s.end()) new_res += res[i];
            }
            res = new_res;
        }
        return res;
    }
};