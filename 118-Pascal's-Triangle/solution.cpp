class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows <= 0) return res;
        
        res.push_back(vector<int>(1,1)); // push first row into res
        
        for(int i=2; i<=numRows; ++i){
            vector<int> cur(i, 1); // initialize i elements in this row, and all has value 1
            vector<int> pre = res[i-2]; // previous row
            for(int j=1; j<i-1; ++j){
                cur[j] = pre[j-1] + pre[j];
            }
            res.push_back(cur);
        }
        
        return res;
    }
};