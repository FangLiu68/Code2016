class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty()) return res;
        
        unordered_map<int, int> mp; // key:nums[i], value:i
        
        for(int i=0; i<nums.size(); ++i){
            int gap = target - nums[i];
            if(mp.find(gap) != mp.end()){
                res.push_back(mp[gap]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};