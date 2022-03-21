///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but interesting
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> m;
        for (int i=0 ; i<s.size() ; i++){
            m[s[i]].push_back(i);
        }
        int start = 0;
        int end = m[s[start]].back();
        vector<int> res;
        for (int i=0 ; i<s.size() ; i++){
            if (i == end){
                res.push_back(end - start + 1);
                if (i + 1 < s.size()){
                    start = i + 1;
                    end = m[s[start]].back();
                }
            }
            if (m[s[i]].back() > end){
                end = m[s[i]].back();
            }
        }
        return res;
    }
};