///////////////////////////////////////////////////////////////////////////////////////////////
// time or memory limit exceeded, just like many solutions proposed by others
////////////////
// Time Complexity: O(hard to articulate)
// Space Complexity: O(hard to articulate)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<pair<string, int>> stack; // state:step
        vector<vector<string>> path;
        unordered_set<string> st;
        
        unordered_set<string> words;
        vector<vector<string>> res;
        
        for (int i=0 ; i<wordList.size() ; i++) words.insert(wordList[i]);
        if (words.find(endWord) == words.end()) return vector<vector<string>>();
        
        st.insert(beginWord);
        stack.push_back(pair<string,int>(beginWord, 1));
        path.push_back(vector<string>{beginWord});
        
        int shortest = INT_MAX;
        
        while (1){
            vector<pair<string,int>> new_stack;
            vector<vector<string>> new_path;
            // for (auto per:stack){
            //     cout << per.first << " " << per.second << endl;
            // }
            while (stack.size()){
                pair<string,int> p = stack.back();
                vector<string> cur_path = path.back();
                
                stack.pop_back();
                path.pop_back();
                
                string str = p.first;
                if (shortest == INT_MAX && str == endWord) {
                    shortest = p.second;
                    res.push_back(cur_path);
                }else if (shortest == p.second && str == endWord){
                    res.push_back(cur_path);
                }
                
                int step = p.second;
                for (int i=0 ; i<str.length() ; i++){
                    for (int j=0 ; j<26 ; j++){
                        string cur = str;
                        cur[i] = char('a' + j);
                        if (words.find(cur) != words.end() && st.find(cur) == st.end()){
                            new_stack.push_back(pair<string, int>(cur,step+1));
                            
                            vector<string> nex_path = vector<string>(cur_path);
                            nex_path.push_back(cur);
                            new_path.push_back(nex_path);
                        }
                    }
                }
            }
            if (new_stack.size()) {
                stack = new_stack;
                path = new_path;
                for (auto per:path){
                    st.insert(per.back());
                }
            } else break;
            
            // check length of path
            int flag = 0;
            for (auto per:stack){
                if (per.second <= shortest) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) break;
        }
        return res;
    }
};