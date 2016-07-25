class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()){
            return res;
        }
        
        int first = first_occur(nums, target);
        int last = last_occur(nums, target);
        
        res.push_back(first);
        res.push_back(last);
        
        return res;
    }
    
    // first occur of target
    int first_occur(vector<int>& nums, int target){
        if(nums.empty()){
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right-1){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid;
            }else{
                right = mid;
            }
        }
        
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        
        return -1;
    }
    
    int last_occur(vector<int>& nums, int target){
        if(nums.empty()){
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right-1){
            int mid = left + (right-left)/2;
            if(nums[mid] == target){
                left = mid;
            }else if(nums[mid] < target){
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