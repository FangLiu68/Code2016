// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 0){
            return -1;
        }
        
        int left = 0;
        int right = n;
        
        while(left < right - 1){
            int mid = left + (right - left)/2;
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        return isBadVersion(left)? left : right;
    }
};