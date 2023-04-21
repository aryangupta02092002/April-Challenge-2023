//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    struct trieNode
    {
        trieNode* children[26];
    };
    
    trieNode* getNode()
    {
        trieNode* newNode = new trieNode();
        for(int i = 0; i<26; i++)
        {
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    
    void insert_trie(trieNode* root, string &word)
    {
        trieNode* crawler = root;
        for(int i = 0; i<word.length(); i++)
        {
            char ch = word[i];
            if(crawler->children[ch-'a']==NULL)
            {
                crawler->children[ch-'a']=getNode();
            }
            crawler = crawler->children[ch-'a'];
        }
    }
    
    bool find_word(trieNode* root, string &word)
    {
        trieNode* crawler = root;
        for(int i = 0; i<word.length(); i++)
        {
            if(crawler->children[word[i]-'a']==NULL)
                return false;
            
            crawler=crawler->children[word[i]-'a'];
        }
        return true;
    }

    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        trieNode* root_front = getNode();
        trieNode* root_back = getNode();
        for(auto str: s1)
        {
            insert_trie(root_front, str);
            string s = str;
            reverse(s.begin(), s.end());
            
            insert_trie(root_back, s);
        }
        int ans = 0;
        for(auto str: s2)
        {
            string s = str;
            reverse(s.begin(), s.end());
            if(find_word(root_front, str) || find_word(root_back, s))
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends
