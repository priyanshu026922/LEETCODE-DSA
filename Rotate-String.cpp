class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m){
            return false;
        }
        if(s==goal)return true;

        for(int i=1;i<n;i++){
             string a=s.substr(i,n-i)+s.substr(0,i);
             if(a==goal)return true;
        }
        return false;
    }

};