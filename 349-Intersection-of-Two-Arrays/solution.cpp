class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
    if(nums1.empty() || nums2.empty()) return vector<int>(0);
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    int index1 = 0;
    int index2 = 0;
    
    while(index1 < nums1.size() && index2 < nums2.size()){
        if(nums1[index1] < nums2[index2]){
            index1++;
        }else if(nums1[index1] > nums2[index2]){
            index2++;
        }else{
            res.insert(nums1[index1]);
            index1++, index2++;
        }
    }
    
    return vector<int>(res.begin(), res.end());
    }
};