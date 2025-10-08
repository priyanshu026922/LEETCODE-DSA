class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int maxi=0;
        stack<char>st;
        for(int i=0;i<n;i++){
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else if(s[i]==')'){
                maxi=max(maxi,(int)st.size());
                st.pop();
                }
            }
        return maxi;
    }
}; 