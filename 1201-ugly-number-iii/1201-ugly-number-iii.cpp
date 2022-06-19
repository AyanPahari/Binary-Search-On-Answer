typedef long long ll;
class Solution {
public:
    
    ll lcm(ll a, ll b){
        return a * b / __gcd(a,b);
    }
    
    ll getCount(ll a, ll b, ll c, ll mid){
        return mid / a + mid / b + mid / c - mid / lcm(a, b) - mid / lcm(b, c) - mid / lcm(a, c) + mid / lcm(a, lcm(b, c));
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        ll N = ll(n), A = ll(a), B = ll(b), C = ll(c);
        ll low = 1, high = 2e9, mid, ans;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            ll cnt = getCount(A, B, C, mid);
            
            if(cnt >= N)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};