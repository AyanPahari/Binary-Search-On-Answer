#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(ll N, ll C, vector<ll> &arr, ll mid){
    ll cows = 1;
    ll prev_loc = 0;
    for(ll i=1;i<N;i++){
        ll curr_loc = i;
        if(abs(arr[curr_loc] - arr[prev_loc]) < mid) continue;
        cows++;
        prev_loc = curr_loc;
        if(cows == C) break;
    }
    return cows == C ? true : false;
}

int main(){
    ll T;
    cin>>T;
    while(T--){
        ll N,C;
        cin>>N>>C;
        vector<ll>arr(N);
        for(ll i=0;i<N;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        ll low = arr[1] - arr[0];
        ll high = arr[N-1] - arr[0];
        ll mid, res;

        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(N,C,arr,mid)){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        cout<<res<<endl;
    }
}