class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        int cur_sum = 0;
        
        while(right < nums.size()){
            cur_sum = cur_sum + nums[right];
            while(cur_sum >= s){
                res = min(res, right-left+1);
                cur_sum = cur_sum - nums[left];
                left++;
            }
            right++;
        }
        
        return res==INT_MAX? 0:res;
    }
};