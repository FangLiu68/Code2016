class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<nums.size(); ++i) sum1 = sum1+nums[i];
        for(int i=0; i<=nums.size(); ++i) sum2 = sum2 + i;
        
        return sum2-sum1;
    }
};