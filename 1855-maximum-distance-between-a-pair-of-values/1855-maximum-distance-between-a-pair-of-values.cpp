class Solution {
public:
    
    int getIndex(vector<int>& nums2, int element, int low, int high){
        int mid, res = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums2[mid] >= element){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res == -1 ? 0 : res;
    }
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // int maxi = 0;
        // for(int i=0;i<nums1.size();i++){
        //     for(int j=nums2.size()-1; j>=i;j--){
        //         if(nums1[i] <= nums2[j]){
        //             maxi = max(maxi, j - i);
        //             break;
        //         }
        //     }
        // }
        // return maxi;
        
        int maxi = 0;
        for(int i=0;i<nums1.size();i++){
            int ind = getIndex(nums2, nums1[i], i, nums2.size() - 1);
            maxi = max(maxi, ind - i);
        }
        return maxi;
    }
};