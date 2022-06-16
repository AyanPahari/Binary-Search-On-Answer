// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   bool isValid(int arr[], int D, int n, int mid){
        int d = 1, sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum > mid){
                sum = arr[i];
                d++;
            }
        }
        return d <= D ? true : false;
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        int low = maxi;
        int high = sum;
        int mid, res;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(arr, D, N, mid)){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends