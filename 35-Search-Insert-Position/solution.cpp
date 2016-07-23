class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        
        if(target <= nums[0]) return 0;
        if(target > nums[nums.size()-1]) return nums.size();
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right-1){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid;
            }else{
                right = mid;
            }
        }
        
        return right;
    }
};