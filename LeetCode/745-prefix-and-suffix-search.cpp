///////////////////////////////////////////////////////////////////////////////////////////////
// hard if using trie tree
////////////////
// Time Complexity: O(n*m*m)
// Space Complexity: O(n*m*m)
///////////////////////////////////////////////////////////////////////////////////////////////
class WordFilter {
public:
    unordered_map<string,int> data;
    WordFilter(vector<string>& words) {
        for (int k = 0; k < words.size(); ++k) {
            string word = words[k];
            for (int i = 1; i <= word.length(); ++i) {
                string key = word.substr(0, i);
                key += '.';
                for (int j = 1; j <= word.length(); ++j) {
                    string new_k = key + word.substr(word.length()-j,j);
                    data[new_k] = k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + '.' + suffix;
        return data.count(s)?data[s]:-1;
    }
};