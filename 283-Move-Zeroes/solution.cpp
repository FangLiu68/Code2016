class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()){
            return;
        }
        
        int slow = 0;
        int fast = 0;
        
        while(fast < nums.size()){
            if(nums[fast] == 0){
                fast++;
            }else{
                nums[slow++] = nums[fast++];
            }
        }
        
        while(slow < nums.size()){
            nums[slow++] = 0;
        }
    }
};