1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        int n=s.length();
5        vector<string>specials;
6     int start=0;
7     int sum=0;
8      
9     for(int i=0;i<n;i++){
10           sum+=((s[i]=='1')?1:-1);
11           if(sum==0){
12            string inner=s.substr(start+1,i-start-1);
13            specials.push_back("1"+makeLargestSpecial(inner)+"0");
14            start=i+1;
15           }
16     }
17     sort(begin(specials),end(specials),greater<string>());
18     string res="";
19     for(string &str:specials){
20        res+=str;
21     }
22     return res;
23    }
24};