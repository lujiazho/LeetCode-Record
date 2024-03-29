///////////////////////////////////////////////////////////////////////////////////////////////
// new data structure of tree to me
////////////////
// Time Complexity: O((n^2)*logn)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    Node* constructQuadTree(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart > rowEnd || colStart > colEnd) return nullptr;
        
        // Check if all elements in the quadrant are the same
        bool isLeaf = true;
        int val = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }
        
        // all elements in the quadrant are the same
        if (isLeaf) return new Node(val, true);
        
        // divide into four sub-grids and recursively construct the quad-tree for each
        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;
        Node* topLeft = constructQuadTree(grid, rowStart, rowMid, colStart, colMid);
        Node* topRight = constructQuadTree(grid, rowStart, rowMid, colMid+1, colEnd);
        Node* bottomLeft = constructQuadTree(grid, rowMid+1, rowEnd, colStart, colMid);
        Node* bottomRight = constructQuadTree(grid, rowMid+1, rowEnd, colMid+1, colEnd);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, n-1, 0, n-1);
    }
};