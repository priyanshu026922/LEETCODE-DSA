1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int n=s.length();
5        vector<int>countOne(n,0);
6        countOne[0]=(s[0]=='1')?1:0;
7        for(int i=1;i<n;i++){
8            countOne[i]=countOne[i-1]+((s[i]=='1')?1:0);
9        }
10
11        int res=0;
12        for(int i=0;i<n;i++){
13            for(int j=i;j<n;j++){
14                int one=countOne[j]-((i-1)>=0?countOne[i-1]:0);
15                int zero=(j-i+1)-one;
16                if((zero*zero)>one){
17                    //slip j to avoid waste indices
18                    int ind=(zero*zero)-one;
19                    j+=(ind-1);
20                }else if((zero*zero)==one){
21                    res+=1;
22                }else{
23                    res+=1;
24                    int k=sqrt(one)-zero;
25                    int nxt=j+k;
26                    if(nxt>=n){
27                        res+=(n-j-1);
28                        break;
29                    }else{
30                        res+=k;
31                    }
32                    j=nxt;
33                }
34                
35            }
36        }
37        return res;
38    }
39};