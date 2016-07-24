class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()){
            return ;
        }
        
        int index_0 = 0;
        int index_1 = 0;
        int index_2 = nums.size() - 1;
        
        while(index_1 <= index_2){
            if(nums[index_1] == 0){
                swap(nums[index_0++], nums[index_1++]);
            }else if(nums[index_1] == 1){
                index_1++;
            }else if(nums[index_1] == 2){
                swap(nums[index_1], nums[index_2--]);
            }
        }
    }
};