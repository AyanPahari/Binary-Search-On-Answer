// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

typedef pair<int, pair<int,int>> ppi;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>res;
        priority_queue<ppi, vector<ppi>, greater<ppi>>minh;
        for(int i=0;i<arr.size();i++) minh.push({arr[i][0],{i, 0}});
        while(!minh.empty()){
            int val = minh.top().first;
            int index = minh.top().second.first;
            int ptr = minh.top().second.second;
            ptr++;
            res.push_back(val);
            minh.pop();
            if(ptr < K) minh.push({arr[index][ptr],{index, ptr}});
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends