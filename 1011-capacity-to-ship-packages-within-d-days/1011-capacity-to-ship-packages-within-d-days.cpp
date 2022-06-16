class Solution {
public:
    
    bool isValid(vector<int>& weights, int days, int mid){
        int d = 1, sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            if(sum > mid){
                sum = weights[i];
                d++;
            }
        }
        return d <= days ? true : false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }
        int low = maxi;
        int high = sum;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(weights, days, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};