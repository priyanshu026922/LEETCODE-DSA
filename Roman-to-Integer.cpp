1class Solution {
2public:
3    int romanToInt(string s) {
4        // I             1
5        // V             5
6        // X             10
7        // L             50
8        // C             100
9        // D             500
10        // M             1000
11        int n=s.length();
12        unordered_map<char,int>mp;
13        mp['I']=1;
14        mp['V']=5;
15        mp['X']=10;
16        mp['L']=50;
17        mp['C']=100;
18        mp['D']=500;
19        mp['M']=1000;
20       
21       int digit=0;
22        for(int i=0;i<n-1;i++){
23            if(mp[s[i]]<mp[s[i+1]]){
24                digit=digit-mp[s[i]];
25            }else{
26                digit=digit+mp[s[i]];
27            }
28        }
29        digit+=mp[s[n-1]];
30        
31        return digit;
32
33        
34    }
35};