///////////////////////////////////////////////////////////////////////////////////////////////
// not really easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        for (int i=0 ; i<s.length() ; i++) m[s[i]] += 1;
        vector<int> v;
        for (auto x:m) v.push_back(x.second);
        sort(v.begin(), v.end());
        int res = 0;
        for (int i=v.size()-1 ; i>0 ; i--){
            if (v[i] <= v[i-1]){
                if (v[i]-1 >= 0){
                    res += v[i-1] - (v[i]-1);
                    v[i-1] = v[i]-1;
                }else{
                    res += v[i-1] - 0;
                    v[i-1] = 0;
                }
            }
        }
        return res;
    }
};
