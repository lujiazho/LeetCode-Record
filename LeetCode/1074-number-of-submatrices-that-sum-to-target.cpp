///////////////////////////////////////////////////////////////////////////////////////////////
// TLE if we use point (x1,y1,x2,y2) to determine a matrix
////////////////
// Time Complexity: O((m^2)*(n^2))
// Space Complexity: O(m*n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> acc(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i=0 ; i<matrix.size() ; i++){
            for (int j=0 ; j<matrix[0].size() ; j++){
                acc[i+1][j+1] = acc[i][j+1] + acc[i+1][j] - acc[i][j] + matrix[i][j];
            }
        }
        int sum = 0, res = 0;
        for (int i=0 ; i<matrix.size() ; i++){
            for (int j=0 ; j<matrix[0].size() ; j++){
                // start from (i, j)
                for (int m=i ; m<matrix.size() ; m++){
                    for (int n=j ; n<matrix[0].size() ; n++){
                        // to (m, n)
                        sum = acc[m+1][n+1] - acc[i][n+1] - acc[m+1][j] + acc[i][j];
                        if (sum == target) res += 1;
                    }
                }
            }
        }
        return res;
    }
};

// improved with hash and change point-determined method to edge-determined method
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> acc(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int i=0 ; i<matrix.size() ; i++){
            for (int j=0 ; j<matrix[0].size() ; j++){
                acc[i+1][j+1] = acc[i][j+1] + acc[i+1][j] - acc[i][j] + matrix[i][j];
            }
        }
        int sum = 0, res = 0;
        for (int top=0 ; top<matrix.size() ; top++){
            for (int bot=top ; bot<matrix.size() ; bot++){
                // within this top and bottom area
                unordered_map<int, int> m; // val : number
                for (int right=0 ; right<matrix[0].size() ; right++){
                    sum = acc[bot+1][right+1] - acc[top][right+1];
                    if (sum == target) res += 1;
                    // search previous boxes that equal to sum-target
                    if (m.count(sum - target)) res += m[sum - target];
                    // store this box area
                    m[sum]++;
                }
            }
        }
        return res;
    }
};