class Solution {
public:
    
    int getCount(int m, int n, int k, int mid){
        int i = 0, j = n - 1;
        int count = 0;
        while(i < m && j >= 0){
            if((i + 1)*(j + 1) <= mid){
                count += j + 1;
                i++;
            }
            else j--;
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            int r = getCount(m, n, k, mid);
            if(r >= k){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};