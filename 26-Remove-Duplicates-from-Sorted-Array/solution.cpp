class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        
        int slow = 0;
        int fast = 1;
        
        while(fast < nums.size()){
            if(nums[slow] == nums[fast]){
                fast++;
            }else{
                nums[++slow] = nums[fast++];
            }
        }
        
        return slow+1;
    }
};