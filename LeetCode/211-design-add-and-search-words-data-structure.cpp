///////////////////////////////////////////////////////////////////////////////////////////////
// it's hard to implement original trie on leetcode with c++, so here is another kind of trie
////////////////
// Time Complexity: O(n), the estimated time complexity is larger than that of original trie
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class WordDictionary {
    unordered_map<int, vector<string>> m;
public:
    WordDictionary() {}
    
    void addWord(string word) {
        m[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for (auto per:m[word.length()]){
            int flag = 1;
            for (int j=0 ; j<word.length() ; j++){
                if (word[j] == '.') continue;
                if (word[j] != per[j]){
                    flag = 0;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
