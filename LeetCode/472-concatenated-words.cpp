///////////////////////////////////////////////////////////////////////////////////////////////
// hard problem because of vague description, solution is good
////////////////
// Time Complexity: O(n*30*30), n is number of words, 30 is max length of word
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);

        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            // not really dp, but brute forcely check if this word can be concatenated by other words
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue; // this will guarantee next sub-word must be right after last sub-word
                for (int j = i + 1; j <= n; j++) {
                    // this would record the tail as 1 if this sub-word exists in words_set
                    // j - i < n ensure that self would not be consider as sub-word
                    if (j - i < n && words_set.count(word.substr(i, j - i))) dp[j] = 1;
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};