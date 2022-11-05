///////////////////////////////////////////////////////////////////////////////////////////////
// c++ version trie, but this TLE
////////////////
// Time Complexity: O(n_words + m*n*(4**10))
// Space Complexity: O(n_words)
///////////////////////////////////////////////////////////////////////////////////////////////
class TrieNode{
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode(){
        is_end=false;
        children=vector<TrieNode*>(26, NULL);
    }   
};

class Trie{
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words){
        root=new TrieNode();
        for(int i=0; i<words.size(); ++i)
            addWord(words[i]);
    }
    void addWord(const string& word){
        TrieNode* cur=root;
        for(int i=0; i<word.size(); ++i){
            int index=word[i]-'a';
            if(cur->children[index]==NULL)   
               cur->children[index]=new TrieNode();
            cur=cur->children[index];    
        }
        cur->is_end=true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root=trie->getRoot();
        set<string> result_set;
        for(int x=0; x<board.size(); ++x)
            for(int y=0; y<board[0].size(); ++y)
                dfs(board, x, y, root, "", result_set);
        
        vector<string> res;
        for(auto it:result_set)    res.push_back(it);
        return res;
    }
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result){
        // use ' ' to record walked cell
        if(x<0||x>=board.size()||y<0||y>=board[0].size() || board[x][y]==' ') return;
        
        // only go when this word exists in trie
        if(root->children[board[x][y]-'a'] != NULL){
            word=word+board[x][y];
            root=root->children[board[x][y]-'a']; 
            if(root->is_end) result.insert(word);
            
            char c=board[x][y]; // record for recovering
            board[x][y]=' ';
            dfs(board, x+1, y, root, word, result);
            dfs(board, x-1, y, root, word, result);
            dfs(board, x, y+1, root, word, result);
            dfs(board, x, y-1, root, word, result);
            board[x][y]=c;
        }
    }
};