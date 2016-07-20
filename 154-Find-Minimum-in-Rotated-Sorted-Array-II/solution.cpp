class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()){
            return INT_MAX;
        }
        int left = 0;
        int right = nums.size()-1;
        while(left < right-1){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid;
            }else{
                right--;
            }
        }
        
        return nums[left]<nums[right]? nums[left]:nums[right];
    }
};