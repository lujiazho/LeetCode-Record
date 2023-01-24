///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), idx = 1;
        vector<int> cells(n*n+1);
        
        for (int row = n - 1; row >= 0; row--) {
            if ((n - row) % 2 == 1) for (int column=0 ; column<n ; column++) cells[idx++] = board[row][column];
            else for (int column=n-1 ; column>=0 ; column--) cells[idx++] = board[row][column];
        }

        vector<int> dist(n*n+1, -1); // store distance
        dist[1] = 0;
        queue<int> q; // bfs queue
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                int val = cells[next];
                int destination = val != -1 ? val : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};