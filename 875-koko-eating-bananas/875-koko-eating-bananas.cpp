class Solution {
public:
    
    bool isValid(vector<int> &piles, int h, int mid){
        long long sum = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] % mid == 0) sum += piles[i] / mid;
            else sum += piles[i] / mid + 1;
        }
        return sum <= h ? true : false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int low = 1;
        int high = maxi;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(piles, h, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};