class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int count=0;
        // vector<string>a;
        // int start=-1;
        // for(int i=0;i<n;i++){
        //    if(s[i]=='('){
        //     count++;
        //    if(start==-1) start=i;

        //     }
        //    if(s[i]==')')count--;

        //    if(count==0){
        //     a.push_back(s.substr(start+1,i-start-1));
        //     start=-1;
        //    }
        // }

        // string ans="";
        // for(auto it:a){
        //     ans+=it;
        // }
        string a="";
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                count--;
            }
            if(count!=0)a+=s[i];
            if(s[i]=='(')count++;
        }
        return a;
    }
};