#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(ll N, ll M, vector<ll> &arr, ll mid){
    ll sum = 0;
    for(ll i=0;i<N;i++){
        if(arr[i] > mid) sum += arr[i] - mid;
        if(sum >= M) return true;
    }
    return false;
}

int main(){
    ll N,M;
    cin>>N>>M;
    vector<ll>arr(N);
    ll maxi = INT_MIN, mini = INT_MAX;
    for(ll i=0;i<N;i++){
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    ll low = mini;
    ll high = maxi;
    ll mid, res;

    while(low <= high){
        mid = low + (high - low) / 2;
        if(isValid(N, M, arr, mid)){
            res = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout<<res<<endl;
    return 0;
}