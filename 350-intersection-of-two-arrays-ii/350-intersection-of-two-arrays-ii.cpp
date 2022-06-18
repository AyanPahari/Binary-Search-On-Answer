class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto it:nums2) mp[it]++;
        vector<int>res;
        
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i]) != mp.end() && mp[nums1[i]] > 0){
                res.push_back(nums1[i]);
                mp[nums1[i]]--;
            }
        }
        return res;
    }
};