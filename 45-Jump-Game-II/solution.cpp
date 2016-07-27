class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int res = 0;
        int index = 0;
        while(curMax < nums.size()-1){
            int lastMax = curMax;
            while(index <= lastMax){
                curMax = max(curMax, index+nums[index]);
                index++;
            }
            res++;
            if(lastMax == curMax) return -1;
        }
        return res;
    }
};