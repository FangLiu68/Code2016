class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
    if(nums1.empty() || nums2.empty()) return vector<int>(0);

    // we suppose nums1.size() < nums2.size()
    if(nums2.size() < nums1.size()){
        return intersection(nums2, nums1);
    }
    
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    
    // search each element in nums2 in nums1
    for(int i=0; i<nums1.size(); ++i){
        int found = helper_binarySearch(nums2, nums1[i]);
        if(found == INT_MIN){
            continue;
        }else{
            res.insert(found);
        }
    }
    
    return vector<int>(res.begin(), res.end());

    }
    
    int helper_binarySearch(vector<int>& input, int target){
    if(input.empty()){
        return INT_MIN;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(input[mid] == target){
            return target;
        }else if(input[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return INT_MIN;
}

};