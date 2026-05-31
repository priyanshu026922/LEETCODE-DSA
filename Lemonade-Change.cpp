1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int n=bills.size();
5        int count5=0;
6        int count10=0;
7        for(int i=0;i<n;i++){
8           if(bills[i]==5)count5++;
9           if(bills[i]==10){
10             if(count5>=1) count10++,count5--;
11             else return false;
12           }
13           if(bills[i]==20){
14            if(count5>=1&&count10>=1)count10--,count5--;
15            else if(count5>=3)count5-=3;
16            else return false;
17           }      
18      }
19      return true;
20    }
21};