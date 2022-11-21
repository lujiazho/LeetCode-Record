///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(mn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> v;
        v.push_back(vector<int>{entrance[0],entrance[1]});
        
        int moves=0;
        int m=maze.size();
        int n=maze[0].size();
        
        vector<vector<int>> offsets={{0,1},{1,0},{0,-1},{-1,0}};
        
        // mark the entrance as visited
        maze[entrance[0]][entrance[1]]='+';
        
        while(!v.empty())
        {
            vector<vector<int>> nex_v;
            for(int k=0 ; k<v.size() ; k++)
            {
                int i=v[k][0], j=v[k][1];
                
                for(int l=0 ; l<4 ; l++)
                {
                    int x = i + offsets[l][0];
                    int y = j + offsets[l][1];
                    // invalid
                    if(x<0 || y<0 || x>=m || y>=n || maze[x][y]=='+') continue;
                    // stand at exit
                    if(x==0 || y==0 || x==m-1 || y==n-1) return moves + 1;
                    
                    maze[x][y] = '+';
                    nex_v.push_back(vector<int>{x,y});
                }
            }
            moves++;
            v = nex_v;
        }
        return -1;
    }
};