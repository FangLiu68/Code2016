class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()){
            return INT_MIN;
        }
        
        vector<int> record(nums.size(), 0);
        record[0] = nums[0];
        int res = record[0];
        
        for(int i=1; i<nums.size(); ++i){
            record[i] = max(record[i-1]+nums[i], nums[i]);
            res = max(res, record[i]);
        }
        
        return res;
    }
};