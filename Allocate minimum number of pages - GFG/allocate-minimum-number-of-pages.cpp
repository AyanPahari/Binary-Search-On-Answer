// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isValid(int A[], int N, int M, int mid){
        int sum = 0;
        int student = 1;
        
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum > mid){
                student++;
                sum = A[i];
            }
            if(student > M) return false;
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<N;i++){
            maxi = max(maxi, A[i]);
            sum += A[i];
        }
        int low = maxi;
        int high = sum;
        int res = -1;
        int mid;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(A, N, M, mid)){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends