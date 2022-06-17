class Solution {
public:
    
    bool isValid(vector<int>& dist, double hour, int mid){
        double time = 0.0;
        for(int i=0;i<dist.size();i++){
            if(i == dist.size() - 1) time += (double)dist[i] / mid;
            else time += ceil((double)dist[i] / mid);
        }
        return time <= hour ? true : false;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e9;
        int mid, res = -1;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(dist, hour, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};