///////////////////////////////////////////////////////////////////////////////////////////////
// hashmap-accelerated
////////////////
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0, s_len = s.size();
        unordered_map<string, bool> m;
        for (auto word: words){
            if (m.find(word) != m.end()) {
                res += m[word]==true?1:0;
                continue;
            }
            int idx = 0, w_size = word.size();
            for (int j=0 ; j<s_len && idx < w_size ; j++){
                if (word[idx] == s[j]) idx ++;
            }
            if (idx >= w_size) {
                res += 1;
                m[word] = true;
            }else m[word] = false;
        }
        return res;
    }
};