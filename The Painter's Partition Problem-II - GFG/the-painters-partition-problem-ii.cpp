// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
   bool isValid(int arr[], int n, int k, long long mid){
        long long sum = 0;
        long long painter = 1;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum > mid){
                painter++;
                sum = arr[i];
            }
            if(painter > k) return false;
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        int maxi = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }
        long long low = maxi;
        long long high = sum;
        long long res = -1;
        long long mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(isValid(arr, n, k, mid)){
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends