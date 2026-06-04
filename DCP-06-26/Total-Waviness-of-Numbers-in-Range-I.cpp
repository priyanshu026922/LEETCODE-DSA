1class Solution {
2public:
3    int getWaviness(int nums){
4        
5        if(nums<100) return 0;
6        int nxt=-1;
7        int cnt=0;
8        int num=nums;
9        while(num>0){
10            int x1=num%10;
11            
12            num/=10;
13
14            int x2=num%10;
15
16            if(nxt!=-1&&num>0){
17                if(x1>nxt&&x1>x2)cnt++;
18                else if(x1<nxt&&x1<x2)cnt++;
19            }
20            nxt=x1;
21        }
22
23        // cout<<nums<<"::::"<<cnt<<endl;
24        return cnt;
25    }
26    int totalWaviness(int num1, int num2) {
27        int ans=0;
28
29        for(int i=num1;i<=num2;i++){
30            int val=getWaviness(i);
31            ans+=val;
32        }
33        return ans;
34    }
35};