class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return INT_MIN;
        }
        
        int close = INT_MAX;
        int res = 0;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i){
            int start = i+1;
            int end = nums.size()-1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target){
                    return sum;
                }
                int gap = abs(target - sum);
                if(gap < close){
                    close = gap;
                    res = sum;
                }
                if(sum < target){
                    start++;
                }else{
                    end--;
                }
            }
        }
        
        return res;
    }
};