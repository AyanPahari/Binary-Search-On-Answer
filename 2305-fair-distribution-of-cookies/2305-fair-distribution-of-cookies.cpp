class Solution {
public:
    
    bool isValid(int maxLimit, vector<int> &cookies, int maxChild)
    {
        do
        {
            int child = 1;
            int currLimit = 0;
            int n = cookies.size();
            for(int i=0;i<n;i++)
            {
                currLimit += cookies[i];
                if(currLimit > maxLimit)
                {
                    child++;
                    currLimit = cookies[i];
                    
                    if(currLimit > maxLimit)
                        return false;
                }
            }
            if(child <= maxChild)
                return true;
        }while(next_permutation(cookies.begin(), cookies.end()));
        return false;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        sort(cookies.begin(), cookies.end());
        
        int low = cookies[n-1];
        int high = 0;
        int mid, res;
        for(int x : cookies)
            high += x;
        
        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(isValid(mid, cookies, k))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
};