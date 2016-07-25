class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()){
            return INT_MIN;
        }
        
        if(triangle.size() == 1){
            return triangle[0][0];
        }
        
        int n = triangle.size();
        vector<int> curPath(n, 0);
        vector<int> prePath(n, 0);
        
        curPath[0] = triangle[0][0];
        
        for(int level = 1; level < n; ++level){
            prePath = curPath;
            curPath[0] = prePath[0] + triangle[level][0];
            curPath[level] = prePath[level-1] + triangle[level][level];
            for(int i=1; i<level; ++i){
                curPath[i] = min(prePath[i-1], prePath[i]) + triangle[level][i];
            }
        }
        
        int minPath = INT_MAX;
        for(int i=0; i<n; ++i){
            minPath = min(minPath, curPath[i]);
        }
        
        return minPath;
    }
};