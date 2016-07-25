class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()){
            return res;
        }
        
        int left = first_occur(nums, target);
        int right = last_occur(nums, target);
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
    
    int first_occur(vector<int> nums, int target){
        if(nums.empty()){
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right - 1){
            int mid = left + (right-left)/2;
            if(nums[mid] >= target){
                right = mid;
            }else{
                left = mid;
            }
        }
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }
    
    int last_occur(vector<int> nums, int target){
        if(nums.empty()){
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right - 1){
            int mid = left + (right - left)/2;
            if(nums[mid] <= target){
                left = mid;
            }else{
                right = mid;
            }
        }
        if(nums[right] == target) return right;
        if(nums[left] == target) return left;
        return -1;
    }
};