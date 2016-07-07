class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty()) return false;
        
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); ++i){
            if(mp.find(nums[i]) != mp.end()){
                int distance = abs(i - mp[nums[i]]);
                if(distance <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        
        return false;
    }
};