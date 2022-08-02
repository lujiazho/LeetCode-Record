///////////////////////////////////////////////////////////////////////////////////////////////
// easy, but a lot techniques: heap, template, bfs
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    template <class T> struct cmp{
        bool operator() (const T& a, const T& b) const {return a[2] > b[2];}
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, cmp<vector<int>>> q;
        q.push(vector<int>{0,0,matrix[0][0]});
        
        while (!q.empty()){
            vector<int> cur = q.top();
            q.pop();
            
            int i=cur[0], j=cur[1], val=cur[2];
            if (!--k) return val;
            
            if (i+1 < n && matrix[i+1][j] != INT_MIN){
                q.push(vector<int>{i+1,j,matrix[i+1][j]});
                matrix[i+1][j] = INT_MIN; // record as walked
            }
            if (j+1 < n && matrix[i][j+1] != INT_MIN){
                q.push(vector<int>{i,j+1,matrix[i][j+1]});
                matrix[i][j+1] = INT_MIN; // record as walked
            }
        }
        return INT_MIN;
    }
};