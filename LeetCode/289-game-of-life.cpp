///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(mn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> nb(m, vector<int>(n, 0));
        for (int i=0 ; i<m ; i++){
            for (int j=0 ; j<n ; j++){
                int num=0;
                if (i>0 && j>0) num += board[i-1][j-1];
                if (i>0) num += board[i-1][j];
                if (i>0 && j<n-1) num += board[i-1][j+1];
                if (j<n-1) num += board[i][j+1];
                if (i<m-1 && j<n-1) num += board[i+1][j+1];
                if (i<m-1) num += board[i+1][j];
                if (i<m-1 && j>0) num += board[i+1][j-1];
                if (j>0) num += board[i][j-1];
                if (num < 2) nb[i][j] = 0;
                else if (2 <= num && num < 3) nb[i][j] = board[i][j];
                else if (3 < num) nb[i][j] = 0;
                else if (num == 3) nb[i][j] = 1;
            }
        }
        board = nb;
    }
};