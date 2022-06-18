class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) low = mid + 1;
            else if(nums[mid] < nums[n-1]) high = mid;
            else high--;
        }
        return nums[low];
    }
};