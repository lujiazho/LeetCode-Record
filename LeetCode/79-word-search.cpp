///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(m*n*(4**word.length))
// Space Complexity: O(word.length)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
        if (!word.size()) return true;
        // out of boundary or not matched
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0]) return false;
        
        char c = board[i][j];
        // set to walked
        board[i][j] = '*';
        // left string need to match
        string s = word.substr(1);
        // go up, down, left, right
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        // set back to not walked
        board[i][j] = c;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                if (dfs(board, i, j, word)) return true;
        return false;
    }
};