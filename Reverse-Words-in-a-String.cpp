class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.length();
        string a="";
        for(int i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                a+=s[i];
            }else{
                 if(a!="")       st.push(a);
                        a="";
            }
        }
        if(a!=""){
            st.push(a);
        }
        string w="";
        while(!st.empty()){
            string u=st.top();
            st.pop();
            w+=u;
            if(!st.empty())w+=' ';
        }
        return w;
    }
};