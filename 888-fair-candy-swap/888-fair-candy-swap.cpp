class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int SA = 0, SB = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<aliceSizes.size();i++){
            SA += aliceSizes[i];
            mp[aliceSizes[i]]++;
        }
        for(int i=0;i<bobSizes.size();i++) SB += bobSizes[i];
        for(int i=0;i<bobSizes.size();i++){
            int x = (SA - SB) / 2 + bobSizes[i];
            if(mp.find(x) != mp.end()){
                return {x, bobSizes[i]};
            }
        }
        return {-1,-1}; // as the answer is guaranteed to exist, so it will never reach this point
    }
};