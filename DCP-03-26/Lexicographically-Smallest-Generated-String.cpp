1class Solution {
2public:
3    bool isSame(string &word,string &str2,int i,int m){
4        for(int j=0;j<m;j++){
5            if(word[i]!=str2[j])return false;
6            i++;
7        }
8        return true;
9    }
10    string generateString(string str1, string str2) {
11        int n=str1.length();
12        int m=str2.length();
13        
14        int N=n+m-1;
15        string word(N,'$');
16        vector<bool>canChange(N,false);
17
18        for(int i=0;i<n;i++){
19            if(str1[i]=='T'){
20               int ind=i;
21               for(int j=0;j<m;j++){
22                    if(word[ind]!='$'&&word[ind]!=str2[j]){
23                        return "";
24                    }
25                    word[ind]=str2[j];
26                   ind++;
27                }
28            }
29        }
30
31        for(int i=0;i<N;i++){
32            if(word[i]=='$'){
33                   word[i]='a';
34                   canChange[i]=true;
35            }
36        }
37
38        for(int i=0;i<n;i++){
39            
40            if(str1[i]=='F'){
41                if(isSame(word,str2,i,m)){
42                    bool changed=false;
43                    for(int ind=i+m-1;ind>=i;ind--){
44                        if(canChange[ind]){
45                            word[ind]='b';
46                            changed=true;
47                            break;
48                        }
49                    }
50
51                    if(changed==false){
52                        return "";
53                    }
54                }
55            }
56        }
57         return word;
58    }
59};