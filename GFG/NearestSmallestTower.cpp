//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<int> st;
        stack<int> st1;
        vector<int> ans(arr.size());
        vector<int> ans1(arr.size());

        for(int i=0; i<arr.size(); i++){
            if(st.empty()){
                ans[i] = -1;
                st.push(i);
            }
            else if(arr[st.top()] < arr[i]){
                ans[i] = st.top();
                st.push(i);
            }
            else if(arr[st.top()] >= arr[i]){
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                ans[i] = st.empty()? -1 : st.top();
                st.push(i);
            }
        }
        
        for(int i=arr.size()-1; i>=0; i--){
            if(st1.empty()){
                ans1[i] = -1;
                st1.push(i);
            }
            else if(arr[st1.top()] < arr[i]){
                ans1[i] = st1.top();
                st1.push(i);
            }
            else if(arr[st1.top()] >= arr[i]){
                while(!st1.empty() && arr[st1.top()] >= arr[i]){
                    st1.pop();
                }
                ans1[i] = st1.empty() ? -1 : st1.top();
                st1.push(i);
            }
        }
  

        for(int i=0; i<ans.size(); i++){
            if(ans[i] == -1 && ans1[i] != -1){
                ans[i] = ans1[i];
            }
            else if(ans[i] != -1 && ans1[i] == -1 || ans[i] == -1 && ans1[i] == -1){
                continue;
            }
            else if(abs(i - ans[i]) > abs(i - ans1[i])){
                ans[i] = ans1[i];
            }
            else if(abs(i - ans[i]) == abs(i - ans1[i])){
                if(arr[ans[i]] <= arr[ans1[i]]){
                    continue;
                }
                else{
                    ans[i] = ans1[i];
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
