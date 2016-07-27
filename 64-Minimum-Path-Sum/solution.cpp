class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return INT_MAX;
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> minCol(col, 0);
        vector<vector<int>> minPath(row, minCol);
        
        minPath[0][0] = grid[0][0];
        
        for(int i=1; i<row; ++i){
            minPath[i][0] = minPath[i-1][0] + grid[i][0];
        }
        
        for(int i=1; i<col; ++i){
            minPath[0][i] = minPath[0][i-1] + grid[0][i];
        }
        
        for(int i=1; i<row; ++i){
            for(int j=1; j<col; ++j){
                minPath[i][j] = min(minPath[i][j-1], minPath[i-1][j]) + grid[i][j];
            }
        }
        
        return minPath[row-1][col-1];
    }
};