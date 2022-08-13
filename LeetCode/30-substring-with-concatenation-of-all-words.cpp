///////////////////////////////////////////////////////////////////////////////////////////////
// use hash to avoid permutation
////////////////
// Time Complexity: O(n*len_of_words)
// Space Complexity: O(len_of_words)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;
        
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> indexes;
        
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j;
            for (j = 0 ; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word]) break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        
        return indexes;
    }
};