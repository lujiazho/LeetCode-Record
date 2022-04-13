///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(1), return does not count in
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int direction = 0; // 0: right, 1: down, 2: left, 3 up
        int x=0,y=0,num=1,N=n*n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        while (v[x][y] == 0){
            v[x][y] = num;
            if (++num > N) break;
            switch (direction){
                case 0:
                    if (y+1 < n && !v[x][y+1]) y++;
                    else { direction = 1; x++;}
                    break;
                case 1:
                    if (x+1 < n && !v[x+1][y]) x++;
                    else { direction = 2; y--;}
                    break;
                case 2:
                    if (y-1 >= 0 && !v[x][y-1]) y--;
                    else { direction = 3; x--;}
                    break;
                case 3:
                    if (x-1 >= 0 && !v[x-1][y]) x--;
                    else { direction = 0; y++;}
                    break;
            }
        }
        return v;
    }
};