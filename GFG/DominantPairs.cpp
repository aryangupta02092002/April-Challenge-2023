//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int binarySearch(vector<int> &arr, int low, int high, int val){
        int idx = -1;
        int n = arr.size();
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] <= val){
                idx = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(idx == -1){
            return 0;
        }
        return idx-n/2+1;
    }
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        for(int i=n/2; i<n; i++){
            arr[i] *= 5;
        }
        sort(arr.begin() + n/2, arr.end());
        int ans = 0;
        for(int i=0; i<n/2; i++){
            int tmp = binarySearch(arr, n/2, n-1, arr[i]);
            ans += tmp;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
