class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> steps(col, INT_MAX);
        steps[0] = 0;
        
        for(int i=0; i < row; ++i){
            steps[0] = steps[0] + grid[i][0];
            
            for(int j=1; j < col; ++j){
                steps[j] = min(steps[j-1], steps[j]) + grid[i][j];
            }
        }
        
        return steps[col-1];
    }
};