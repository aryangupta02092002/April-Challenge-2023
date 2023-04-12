class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans;
        
        for(int i=0; i<path.size(); i++){
            if(path[i] == '/'){
                continue;
            }
            string tmp;
            while(i<path.size() && path[i] != '/'){
                tmp += path[i];
                ++i;
            }
            if(tmp == "."){
                continue;
            }
            else if(tmp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(tmp);
            }
        }
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.size() == 0){
            return "/";
        }
        return ans;
    }
};
