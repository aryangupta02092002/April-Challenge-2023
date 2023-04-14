//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        vector<int> prev(n);
        int i;
        prev[0]=-1;
        for(i=1;i<n;i++) prev[i]=i-1;
        int curr=1,ans=n;
        while(curr<n){
            if(prev[curr]>=0 && color[curr]==color[prev[curr]] && radius[curr]==radius[prev[curr]]){
                ans-=2;
                if(curr+1<n){
                    prev[curr+1] = prev[prev[curr]];
                }
            }
            curr++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
