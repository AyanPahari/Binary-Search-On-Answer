class Solution {
public:
    
    bool isValid(vector<int>& time, int T, long long mid){
        unsigned long long count = 0;
        for(int i=0;i<time.size();i++) count += mid / time[i];
        return count >= T ? true : false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e18;
        long long mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(time, totalTrips, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};