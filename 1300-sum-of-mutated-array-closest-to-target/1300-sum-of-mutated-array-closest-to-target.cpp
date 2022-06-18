class Solution {
public:
    
    int isValid(vector<int>& arr, int target, int mid){
        int sum = 0;
        for(int i=0;i<arr.size();i++) sum += min(arr[i], mid);
        return abs(sum - target);
    }
    
    int findBestValue(vector<int>& arr, int target) {
        int low = 0;
        int high = 1e5;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(arr, target, mid) <= isValid(arr, target, mid + 1)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};