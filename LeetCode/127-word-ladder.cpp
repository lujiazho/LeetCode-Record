///////////////////////////////////////////////////////////////////////////////////////////////
// not so hard, just a little bit complex, using bfs
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<pair<string, int>> stack; // state:step
        unordered_set<string> st;
        unordered_set<string> words;
        for (int i=0 ; i<wordList.size() ; i++){
            words.insert(wordList[i]);
        }
        st.insert(beginWord);
        stack.push_back(pair<string,int>(beginWord, 1));
        while (1){
            vector<pair<string,int>> new_stack;
            while (stack.size()){
                pair<string,int> p = stack.back();
                stack.pop_back();
                string str = p.first;
                if (str == endWord){
                    return p.second;
                }
                int step = p.second;
                for (int i=0 ; i<str.length() ; i++){
                    for (int j=0 ; j<26 ; j++){
                        string cur = str;
                        cur[i] = char('a' + j);
                        if (words.find(cur) != words.end() && st.find(cur) == st.end()){
                            new_stack.push_back(pair<string, int>(cur,step+1));
                            st.insert(cur);
                        }
                    }
                }
            }
            if (new_stack.size()) stack = new_stack;
            else break;
        }
        return 0;
    }
};