1class Solution {
2public:
3    bool checkValidString(string s) {
4        int n=s.length();
5        int mini=0;
6        int  maxi=0;
7        for(int i=0;i<n;i++){
8            if(s[i]=='('){
9                mini++;
10                maxi++;
11            }else if(s[i]==')'){
12                mini=max(0,mini-1);
13                maxi--;
14            }else{
15                mini=max(0,mini-1);
16                maxi++;
17            }
18            if(maxi<0){
19                return false;
20            }
21        }
22        
23        if(mini==0){
24            return true;
25        }
26        return false;
27    }
28};