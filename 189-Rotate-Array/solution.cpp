class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()){
            return;
        }
        
        k = k % nums.size();
        
        helper_swap(nums, 0, nums.size()-1);
        helper_swap(nums, 0, k-1);
        helper_swap(nums, k, nums.size()-1);
    }
    
    void helper_swap(vector<int>& nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++, end--;
        }
    }
};