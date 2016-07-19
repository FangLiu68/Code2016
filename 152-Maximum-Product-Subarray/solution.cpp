class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()){
            return INT_MIN;
        }
        
        vector<int> record_min(nums.size(), 1);
        vector<int> record_max(nums.size(), 1);
        record_min[0] = record_max[0] = nums[0];
        int res = record_max[0];
        
        for(int i=1; i<nums.size(); ++i){
            record_min[i] = min(nums[i], min(record_min[i-1]*nums[i], record_max[i-1]*nums[i]));
            record_max[i] = max(nums[i], max(record_max[i-1]*nums[i], record_min[i-1]*nums[i]));
            res = max(res, record_max[i]);
        }
        
        return res;
    }
};