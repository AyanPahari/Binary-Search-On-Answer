class Solution {
public:
    
    bool isValid(vector<int> &bloomDay, int m, int k, int mid){
        int count = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            if(bloomDay[i] > mid) count = 0;
            if(count == k){
                count = 0;
                m--;
            }
            if(m == 0) return true;
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m * k) return -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        int mid;
        int res = -1;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(bloomDay, m, k, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};