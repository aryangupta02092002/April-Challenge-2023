class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int sz = pushed.size();
        int j=0;
        stack<int> st;
        
        for(int x : pushed){
            st.push(x);
            while(!st.empty() && j<sz && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }
        return j==sz;
    }
};
