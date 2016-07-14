class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty()) return vector<int>();
    
        int i=0;
        for(i=digits.size()-1; i>=0; --i){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i]++;
                return digits;
            }
        }
    
        if(i<0){
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};