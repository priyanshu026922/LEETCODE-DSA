1class Solution {
2public:
3    int countOnBits(int num1){
4        int c=0;
5        for(int i=0;i<=6;i++){
6            if(num1&(1<<i)){
7                c++;
8            }
9        }
10        return c;
11    }
12
13    vector<string> readBinaryWatch(int turnedOn) {
14        vector<string>ans;
15        for(int i=0;i<=turnedOn;i++){
16            int hour=i;//NUMBER OF TURNED ON BITS IN HOUR 
17            int min=turnedOn-i;
18            if(hour<=3&&min<=5){
19                for(int num1=0;num1<=11;num1++){
20                    string s="";
21                    int cnt1=countOnBits(num1);
22
23                    if(cnt1==hour){
24                        s+=to_string(num1);
25                        s+=':';
26                    for(int num2=0;num2<=59;num2++){
27                        string st=s;
28                        int cnt2=countOnBits(num2);
29                        if(cnt2==min){
30                            if(num2<10){
31                                st=st+'0'+to_string(num2);
32                            }else{
33                                st+=to_string(num2);
34                            }
35                             ans.push_back(st);
36                        }else{
37                            continue;
38                        }
39                       
40                    }
41                    }
42                }
43            }
44        }
45
46        return ans;
47    }
48};