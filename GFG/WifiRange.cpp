//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string s, int X){
        // code here
        int temp=0;
        for(int i=0;i<N;i++)
        {
            if(s[i]=='1')
            temp=X;
            else
            {
                if(temp>0)
                {
                    s[i]='1';
                    temp--;
                }
            }
        }
        for(int i=N-1;i>=0;i--)
        {
            if(s[i]=='1')
            temp=X;
            else
            {
                if(temp>0)
                {
                    s[i]='1';
                    temp--;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(s[i]=='0') return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
