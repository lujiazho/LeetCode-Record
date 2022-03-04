///////////////////////////////////////////////////////////////////////////////////////////////
// not so easy, but not really hard
////////////////
// Time Complexity: O(100*100)
// Space Complexity: O(100*100)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    double glasses[100][100] = {0};
    double champagneTower(int poured, int query_row, int query_glass) {
        glasses[0][0] = poured;
        for (int i=1 ; i<100 ; i++){
            for (int j=0 ; j<=i ; j++){
                if (glasses[i-1][j]-1>0) glasses[i][j] += (glasses[i-1][j]-1)/2.0;
                if (j > 0 && glasses[i-1][j-1]-1>0) glasses[i][j] += (glasses[i-1][j-1]-1)/2.0;
            }
        }
        return glasses[query_row][query_glass]>1?1:glasses[query_row][query_glass];
    }
};