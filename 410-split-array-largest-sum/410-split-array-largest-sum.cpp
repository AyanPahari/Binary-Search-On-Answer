class Solution {
public:
    
    bool isValid(vector<int> &nums, int m, int mid){
        int sum = 0, split = 1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > mid){
                sum = nums[i];
                split++;
            }
        }
        return split <= m ? true : false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        
        int low = maxi;
        int high = sum;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(nums, m, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};