class Solution {
public:
    
    bool isValid(vector<int> arr, int m, int mid){
        int b = 1;
        int prev = arr[0];
        for(int i=1;i<arr.size();i++){
            int curr = arr[i];
            if(curr - prev >= mid){
                b++;
                prev = curr;
            }
            if(b == m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& arr, int m) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 1;
        int high = 1e9;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(arr, m, mid)){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res;
    }
};