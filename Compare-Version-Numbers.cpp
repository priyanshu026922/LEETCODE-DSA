1class Solution {
2public:
3    int compareVersion(string version1, string version2) {
4        int n=version1.length();
5        int m=version2.length();
6        
7        string a="";
8        string b="";
9        vector<string>first;
10        vector<string>sec;
11        
12        for(int i=0;i<n;i++){
13            if(version1[i]=='.'){
14                first.push_back(a);
15                a="";
16            }
17            else a+=version1[i];
18        }
19
20        if(a!="")first.push_back(a);
21        
22        for(int i=0;i<m;i++){
23            if(version2[i]=='.'){
24                sec.push_back(b);
25                b="";
26            }else{
27                b+=version2[i];
28            }
29        }
30        if(b!="")sec.push_back(b);
31
32        int n1=first.size();
33        int m1=sec.size();
34
35        if(n1>m1){
36           int val=n1-m1;
37            for(int i=0;i<val;i++){
38                sec.push_back("0");
39            }
40        }
41        else if(n1<m1){
42            int val=m1-n1;
43            for(int i=0;i<val;i++){
44                first.push_back("0");
45            }
46        }
47
48
49        n1=first.size();
50        m1=sec.size();
51
52
53
54
55        int i=0;
56        int j=0;
57        while(i<n1&&j<m1){
58           int s1=stoi(first[i]);
59           int s2=stoi(sec[j]);
60
61           if(s1>s2){
62            return 1;
63           }
64           if(s1<s2){
65            return -1;
66           }
67           i++;
68           j++;
69        }
70        
71
72        return 0;
73        
74    }
75};