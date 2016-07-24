class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return;
        
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;
        
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 0){
                count_zero++;
            }else if(nums[i] == 1){
                count_one++;
            }else{
                count_two++;
            }
        }
        
        int index = 0;
        while(index < nums.size()){
            for(int i=0; i<count_zero; ++i){
                nums[index++] = 0;
            }
            for(int i=0; i<count_one; ++i){
                nums[index++] = 1;
            }
            for(int i=0; i<count_two; ++i){
                nums[index++] = 2;
            }
        }
    }
};