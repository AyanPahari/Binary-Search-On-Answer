class Solution {
public:
    
    int getCount(vector<int>arr){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int mid,res = -1;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] == 1){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res == -1 ? 0 : res + 1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>arr;
        for(int i=0;i<mat.size();i++) arr.push_back({getCount(mat[i]), i});
        
        sort(arr.begin(),arr.end());
        vector<int>res;
        for(int i=0;i<k;i++) res.push_back(arr[i].second);
        return res;
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        // return {1,1};
    }
};