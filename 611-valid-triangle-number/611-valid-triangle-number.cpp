class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if(nums.size() < 2) return count;
        sort(nums.begin(),nums.end());
        for(int i=2;i<nums.size();i++){
            int L = 0;
            int R = i - 1;
            while(L < R){
                if(nums[L] + nums[R] > nums[i]){
                    count += R - L;
                    R--;
                }
                else L++;
            }
        }
        return count;
    }
};