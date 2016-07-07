class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty() || nums2.empty() || m<0 || n<0){
        return;
    }
    
    int last_merge_index = m+n-1;
    int last1 = m-1;
    int last2 = n-1;
    
    while(last1>=0 && last2>=0){
        nums1[last_merge_index--] = (nums1[last1]>nums2[last2])? nums1[last1--] : nums2[last2--];
    }
    
    while(last2 >= 0){
        nums1[last_merge_index--] = nums2[last2--];
    }
    }
};