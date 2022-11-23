///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // used1[i][j]: in i-th row, the j+1 exists or not
        // used1[i][j]: in i-th column, the j+1 exists or not
        // used3[i][j]: in i-th 9-board, the j+1 exists or not
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i) {
            for(int j = 0; j < board[i].size(); ++ j) {
                if(board[i][j] != '.') {
                    // num: 0-8, represents 1-9
                    int num = board[i][j] - '0' - 1;
                    // k: which 9-board this number is in, at most 9 9-board's
                    int k = i / 3 * 3 + j / 3;
                    // no same number on this row, column, and 9-board
                    if(used1[i][num] || used2[j][num] || used3[k][num]) return false;
                    // set to 1, meaning exists
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
            }
        }
        
        return true;
    }
};