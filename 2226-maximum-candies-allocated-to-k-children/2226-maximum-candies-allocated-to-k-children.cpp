class Solution {
public:
    
    bool isValid(vector<int> &candies, long long k, long long mid){
        long long count = 0;
        for(int i=0;i<candies.size();i++){
            count += candies[i] / mid;
            if(count >= k) return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(int i=0;i<candies.size();i++) sum += candies[i];
        if(sum < k) return 0;
        
        long long low = 1;
        long long high = sum;
        long long mid, res = 0;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(candies, k, mid)){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res;
    }
};