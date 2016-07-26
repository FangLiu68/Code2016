class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        
        int res = 0;
        int minPrice = prices[0];
        
        for(int i=1; i<prices.size(); ++i){
            if(prices[i] > minPrice){
                res = max(prices[i] - minPrice, res);
            }else{
                minPrice = prices[i];
            }
        }
        
        return res;
    }
};