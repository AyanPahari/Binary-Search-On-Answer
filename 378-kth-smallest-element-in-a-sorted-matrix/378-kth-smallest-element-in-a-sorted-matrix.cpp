class Solution {
public:
    
    int rank(vector<vector<int>>& matrix, int k, int mid){
        int count = 0;
        int n = matrix.size();
        int i = 0;
        int j = n-1;
        
        while(i < n && j >= 0){
            if(matrix[i][j] <= mid){
                count += j + 1;
                i++;
            }
            else j--;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            int r = rank(matrix, k, mid);
            if(r >= k){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};