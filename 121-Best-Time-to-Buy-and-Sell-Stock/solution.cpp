class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int cur_min = prices[0];
        int max_diff = 0;
        
        for(int i=1; i<prices.size(); ++i){
            max_diff = max(max_diff, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        
        return max_diff;
    }
};