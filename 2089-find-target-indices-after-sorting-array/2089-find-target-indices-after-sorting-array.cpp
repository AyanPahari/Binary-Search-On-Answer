class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, less = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < target) less++;
            if(nums[i] == target) count++;
        }
        vector<int>res;
        while(count--) res.push_back(less++);
        return res;
    }
};