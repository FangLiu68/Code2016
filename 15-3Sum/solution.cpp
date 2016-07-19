class Solution {
public:

/*
 去重复的宗旨是：排序后，只要这次遇见的数与上次相邻的遇见的书相同，我们就跳过，走下一个
 注意：
 1. base case: nums.size() < 3
 2. condition to jump current i:
 if(i>0 && nums[i]==nums[i-1]) continue;
 or
 we only do under condition if(i==0 || nums[i]>nums[i-1])
 3. condition to jum current start and end
 while(start<end && ...)   here we should use while
 */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
    
        vector<int> cur(3, 0);
        sort(nums.begin(), nums.end());
    
        for(int i=0; i<nums.size()-2; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
        
            // if(i==0 || nums[i]>nums[i-1]){
            int start = i+1;
            int end = nums.size() - 1;
            while(start < end){
                int sum = nums[start] + nums[end];
                if(nums[i] + sum == 0){
                    cur[0] = nums[i];
                    cur[1] = nums[start++];
                    cur[2] = nums[end--];
                    res.push_back(cur);
                
                    // 去重复. start和end更新后和之前的值作比较
                    while(start<end && nums[start]==nums[start-1]) start++;
                    while(start<end && nums[end]==nums[end+1]) end--;
                }else if(nums[i] + sum < 0){
                    start++;
                }else{
                    end--;
                }
            }
        //}
        }
        
        return res;
    }
};