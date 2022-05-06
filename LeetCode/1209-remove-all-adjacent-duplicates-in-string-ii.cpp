///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<char> v;
        vector<int> num; // continuously number of same letter
        for (int i=0 ; i<s.length() ; i++){
            if (v.size()){
                if (s[i] == v[v.size()-1]){
                    num.push_back(num[num.size()-1]+1);
                }else
                    num.push_back(1);
            }else
                num.push_back(1);
            v.push_back(s[i]);
            if (num[num.size()-1] == k){
                int n = k;
                while (n--){
                    v.pop_back();
                    num.pop_back();
                }
            }
        }
        string res;
        for (int i=0 ; i<v.size() ; i++)
            res += v[i];
        return res;
    }
};