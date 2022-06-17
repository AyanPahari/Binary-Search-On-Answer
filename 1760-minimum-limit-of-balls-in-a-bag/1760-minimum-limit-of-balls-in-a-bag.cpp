class Solution {
public:
    
    bool isValid(vector<int> &nums, int Op, int mid){
        int part = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > mid){
                if(nums[i] % mid == 0) part += nums[i] / mid - 1;
                else part += nums[i] / mid;
            }
        }
        return part <= Op ? true : false;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(nums, maxOperations, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};