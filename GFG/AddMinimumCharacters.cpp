//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int i = 0, j = str.length() - 1;
        int count = 0;
        
        while(i <= j){
            if(str[i] == str[j]){
                count = 0;
                int temp = j;
                while(i<j && str[i] == str[j]){
                    i++;
                    j--;
                    count++;
                }
                if(i >= j){
                    break;
                }
                else{
                    count = 0;
                    i = 0;
                    j = temp-1;
                }
            }
            else{
                j--;
            }
        }
    
        if(i == j){
            return (str.length() - (2*count+1));
        }
        return (str.length() - (2*count));
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
