class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex < 0){
            return res;
        }
        
        for(int i=0; i<=rowIndex; ++i){
            for(int j=i-1; j>0; --j){
                res[j] = res[j-1] + res[j];
            }
            res.push_back(1);
        }
        
        return res;
    }
};