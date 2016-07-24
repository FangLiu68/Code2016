class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row*col - 1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int mid_row = mid / col;
            int mid_col = mid % col;
            if(matrix[mid_row][mid_col] == target){
                return true;
            }else if(matrix[mid_row][mid_col] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        return false;
    }
};