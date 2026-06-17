1class Solution {
2public:
3  void getStrings(string curr,int size,  vector<string>&s,int num){
4      if(size==num){
5          s.push_back(curr);
6          return;
7      }
8      
9      if(curr.back()!='0'){
10      getStrings(curr+'0',size+1,s,num);
11      }
12       getStrings(curr+'1',size+1,s,num);
13      
14       return;
15  }
16  
17    vector<string> validStrings(int num) {
18        vector<string>s;
19       if(num==1){
20           s.push_back("0");
21           s.push_back("1");
22           return s;
23       }
24       getStrings("0",1,s,num);
25       getStrings("1",1,s,num);
26       return s;
27    }
28};