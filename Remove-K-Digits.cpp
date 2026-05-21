1class Solution {
2public:
3    string removeKdigits(string num, int k) {
4        int n=num.length();
5        stack<int>s;
6        int i;
7        for(i=0;i<n;i++){
8             int val=num[i]-'0';
9             while(!s.empty()&&k>0&&s.top()>=val){
10                s.pop();
11                k--;
12             }
13
14
15             s.push(val);
16        }
17        while(k>0){
18            s.pop();
19            k--;
20        }
21
22        if(s.empty()){
23            return "0";
24        }
25
26        string ans="";
27        while(!s.empty()){
28            ans+=(s.top()+'0');
29            s.pop();
30        }
31
32        while(ans.size()>0&&ans.back()=='0'){
33            ans.pop_back();
34        }
35       
36        reverse(begin(ans),end(ans));
37        cout<<"i::"<<i<<endl;
38         cout<<ans<<endl;
39         if(ans.size()==0){
40            return "0";
41         }
42         
43 
44        return ans;
45    }
46};