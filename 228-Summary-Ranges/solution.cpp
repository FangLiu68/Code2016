class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start = 0;
        int end = 0;
        while(end < nums.size()){
            while(end < nums.size()-1 && nums[end+1]-nums[end]==1){
                end++;
            }
            res.push_back(helper(nums[start], nums[end]));
            start = end+1;
            end = start;
        }
        return res;
    }
    
    string helper(int from, int to){
        stringstream temp;
        if(from == to){
            temp << from;
        }else{
            temp << from << "->" << to;
        }
        return temp.str();
    }
};