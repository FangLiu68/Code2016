class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()){
            return INT_MIN;
        }
        
        if(nums.size() == 1){
            return 0;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right-1){
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid] < nums[mid-1]){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        return nums[left]>nums[right]? left:right;
    }
};