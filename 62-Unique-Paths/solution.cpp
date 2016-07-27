class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n<1){
            return 0;
        }
        
        vector<int> paths(n, 1);
        
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                paths[j] = paths[j] + paths[j-1];
            }
        }
        
        return paths[n-1];
    }
};