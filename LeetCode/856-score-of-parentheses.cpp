///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> v;
    int scoreOfParentheses(string s) {
        int i = 0;
        while (i<s.length()){
            if (s[i] == '('){
                v.push_back("(");
            }else{
                if (v[v.size()-1] == "("){
                    v.pop_back();
                    v.push_back("1");
                    check();
                }else{
                    int num = 1;
                    if (v.back() != "("){
                        num = 2*stoi(v.back());
                        v.pop_back();
                    }
                    v.pop_back();
                    v.push_back(to_string(num));
                    check();
                }
            }
            i++;
        }
        return stoi(v[0]);
    }
    void check(){
        if (v.size() > 1 && v[v.size()-1] != "("){
            while (v.size() > 1 && v[v.size()-2] != "("){
                int last = stoi(v[v.size()-1]);
                v.pop_back();
                v[v.size()-1] = to_string(stoi(v[v.size()-1]) + last);
            }
        }
    }
};