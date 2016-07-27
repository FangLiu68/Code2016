class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int res = 0;
        int i = 0;
        while(curMax < nums.size()-1){
            int lastMax = curMax;
            for(; i <= lastMax; ++i){
                curMax = max(curMax, i+nums[i]);
            }
            res++;
            if(lastMax == curMax) return -1;
        }
        return res;
    }
};