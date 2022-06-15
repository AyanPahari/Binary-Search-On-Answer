#include<bits/stdc++.h>
using namespace std;

bool isValid(int P, int C, vector<int> &ranks, int mid){
    int count = 0;
    for(int i=0;i<C;i++){
        int n = 0;
        while(ranks[i] * n * (n + 1) / 2 <= mid){
            n++;
        }
        count += n - 1;
        if(count >= P) return true;
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int P,C;
        cin>>P>>C;
        vector<int>ranks(C);
        int mini = INT_MAX;
        for(int i=0;i<C;i++){
            cin>>ranks[i];
        }
        sort(ranks.begin(), ranks.end());

        int low = 1;
        int high = ranks[0] * P * (P + 1) / 2;
        int mid,res;

        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(P, C, ranks, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        cout<<res<<endl;
    }
    return 0;
}