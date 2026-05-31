1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int n=bills.size();
5        int cnt5=0;
6        int cnt10=0;
7        int cnt20=0;
8        for(int i=0;i<n;i++){
9            if(bills[i]==5){
10                cnt5++;
11            }else if(bills[i]==10){
12                if(cnt5>0){
13                    cnt5--;
14                    cnt10++;
15                }else{
16                    return false;
17                }
18            }else{
19                if(cnt5>0&&cnt10>0){
20                    cnt10--;
21                    cnt5--;
22                }else if(cnt5>=3){
23                   cnt5-=3;
24                }else{
25                    return false;
26                }
27            }
28        }
29        return true;
30    }
31};