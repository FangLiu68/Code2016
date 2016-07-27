class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(row <= 0 || col <= 0) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<int> steps(col, 1);
        
        for(int j = 1; j < col; ++j){
            if(obstacleGrid[0][j] == 1){
                steps[j] = 0;
            }else{
                steps[j] = steps[j-1];
            }
        }
        
        for(int i = 1; i < row; ++i){
            steps[0] = obstacleGrid[i][0] == 1? 0 : steps[0];
            for(int j = 1; j < col; ++j){
                steps[j] = obstacleGrid[i][j] == 1? 0 : steps[j]+steps[j-1];
            }
        }
        
        return steps[col-1];
    }
};