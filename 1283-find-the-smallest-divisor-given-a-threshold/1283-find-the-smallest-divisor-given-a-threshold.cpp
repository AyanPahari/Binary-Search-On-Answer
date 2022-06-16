class Solution {
public:
    
    bool isValid(vector<int> &nums, int threshold, int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % mid == 0) sum += nums[i] / mid;
            else sum += nums[i] / mid + 1;
        }
        return sum <= threshold ? true : false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(),nums.end());
        int low = 1;
        int high = maxi;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(nums, threshold, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};