1class Solution {
2public:
3void getString(string &s){//FOR ODD Case
4    int n=s.length();
5    bool b=false;
6    int i=n-1;
7    while(i>=0&&s[i]!='0'){
8        s[i]='0';
9        i--;
10    }
11    
12    if(i<0){
13        s="1"+s;
14        return;
15    }
16        s[i]='1';
17   
18}
19
20    int numSteps(string s) {
21        int n=s.length();
22        int cnt=0;
23        int last=n-1;
24        while(s.length()>1){
25            int m=s.length();
26            if(s[m-1]=='1'){//ODD
27               getString(s);
28            }else{//EVEN
29            //    getLeft(s);
30               s=s.substr(0,m-1);
31            }
32            cnt++;
33        }
34        return cnt;
35    }
36};