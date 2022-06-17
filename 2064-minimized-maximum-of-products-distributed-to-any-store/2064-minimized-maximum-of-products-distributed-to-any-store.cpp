class Solution {
public:
    
    bool isValid(int n, vector<int> arr, int mid){
        int count = 0;
        for(int i=0;i<arr.size();i++){
            while(arr[i] > 0){
                if(arr[i] > mid){
                    arr[i] -= mid;
                }
                else arr[i] = 0;
                count++;
            }
        }
        return count <= n ? true : false;
    }
    
    int minimizedMaximum(int n, vector<int>& arr) {
        int low = 1;
        int high = *max_element(arr.begin(),arr.end());
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(n, arr, mid)){
                res = mid;
                cout<<res<<endl;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};