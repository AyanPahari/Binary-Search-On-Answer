class Solution {
public:
    
    bool isValid(vector<int>cookies, int k, int mid){
        do{
            int child = 1;
            int sum = 0;
            for(int i=0;i<cookies.size();i++){
                if(cookies[i] > mid) return false;
                
                sum += cookies[i];
                if(sum > mid){
                    child++;
                    sum = cookies[i];
                }
            }
            if(child <= k) return true;
        }while(next_permutation(cookies.begin(), cookies.end()));
        return false;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(),cookies.end());
        int low = *max_element(cookies.begin(),cookies.end());
        int high = 0;
        for(auto it:cookies) high += it;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(cookies, k, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};