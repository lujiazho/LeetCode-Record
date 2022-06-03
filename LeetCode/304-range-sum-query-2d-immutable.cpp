///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class NumMatrix {
public:
    vector<vector<int>> accmat;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() > 1)
            for (int i=1 ; i<matrix.size() ; i++)
                matrix[i][0] += matrix[i-1][0];
        if (matrix[0].size() > 1)
            for (int j=1 ; j<matrix[0].size() ; j++)
                matrix[0][j] += matrix[0][j-1];
        if (matrix.size() > 1 && matrix[0].size() > 1)
        for (int i=1 ; i<matrix.size() ; i++){
            for (int j=1 ; j<matrix[0].size() ; j++){
                matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
            }
        }
        accmat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > 0 && col1 > 0)
            return accmat[row2][col2] - accmat[row1-1][col2] - accmat[row2][col1-1] + accmat[row1-1][col1-1];
        else if (row1 == 0 && col1 > 0)
            return accmat[row2][col2] - accmat[row2][col1-1];
        else if (col1 == 0 && row1 > 0)
            return accmat[row2][col2] - accmat[row1-1][col2];
        return accmat[row2][col2];
    }
};