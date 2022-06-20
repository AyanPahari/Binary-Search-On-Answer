class Solution {
public:
    
    int isValid(vector<int> &nums, int mid){
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= mid) count++;
        }
        return count;
    }
    
    int specialArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        int mid;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            int count = isValid(nums, mid);
            if(count == mid) return mid;
            else if(count > mid) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};