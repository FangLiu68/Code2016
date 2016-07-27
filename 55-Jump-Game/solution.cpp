class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()){
            return false;
        }
        
        int maxIndex = 0;
        for(int i=0; i<nums.size(); ++i){
            if(maxIndex >= nums.size()-1 || i > maxIndex) break;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        
        return maxIndex>=nums.size()-1 ? true:false;
    }
};