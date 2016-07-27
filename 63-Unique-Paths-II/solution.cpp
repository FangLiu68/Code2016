class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(row <= 0 || col <= 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<int> steps(col, 0);
        steps[0] = 1;
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(obstacleGrid[i][j] == 0 && j > 0){
                    steps[j] = steps[j-1] + steps[j];
                }else if(obstacleGrid[i][j] == 1){
                    steps[j] = 0;
                }
            }
        }
        
        return steps[col-1];
    }
};