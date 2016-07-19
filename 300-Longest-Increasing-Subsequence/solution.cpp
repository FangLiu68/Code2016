class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        vector<int> record(nums.size(), 1);
        int res = record[0];
        
        for(int i=1; i<nums.size(); ++i){
            int cur_max = 0;
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    cur_max = max(cur_max, record[j]);
                }
            }
            record[i] = cur_max + 1;
            res = max(res, record[i]);
        }
        
        return res;
    }
};