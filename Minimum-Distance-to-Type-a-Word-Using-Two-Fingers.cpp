1class Solution {
2public:
3 int dp[301][27][27];
4    int solve(string &word,int ind,char f1,char f2){
5        if(ind==word.length()){
6            return 0;
7        }
8
9        if(dp[ind][f1-'A'][f2-'A']!=-1)return dp[ind][f1-'A'][f2-'A'];
10
11        int x=(word[ind]-'A')/6;
12        int y=(word[ind]-'A')%6;
13          
14        int mini=INT_MAX;
15        //NO FINGER IS MOVED TILL NOW:PICK ANY ONE:---
16        // if((x1==-1&&y1==-1)&&(x2==-1&&y2==-1)){
17        //    mini= solve(word,ind+1,x,y,x2,y2);
18        // } 
19        if(f1=='['&&f2=='['){
20            mini=solve(word,ind+1,word[ind],f2);
21        }
22        
23        //Second finger is not moved till now
24        //FIrst move ho chuka hoga
25        // if(x2==-1&&y2==-1){
26        //     //move the second finger
27        //     int val1=solve(word,ind+1,x1,y1,x,y);
28        //     //still dont move the second finger
29        //     //go with moving 1st finger 
30        //     int val2=(abs(x-x1)+abs(y-y1))+solve(word,ind+1,x,y,x2,y2);
31        //     mini = min({mini, val1, val2});
32        // }
33        int x1=(f1-'A')/6;
34        int y1=(f1-'A') %6 ;
35      
36        if(f2=='['){
37            int val1=solve(word,ind+1,f1,word[ind]);
38            int val2=(abs(x-x1)+abs(y-y1))+solve(word,ind+1,word[ind],f2);
39               mini = min({mini, val1, val2});
40        }
41
42        
43        //First fingeer hi abtak move nhi kia hai
44        //2nd wla kar chuka hai move
45        //  if(x1==-1&&y1==-1){
46        //     //move the first finger
47        //     int val1=solve(word,ind+1,x,y,x2,y2);
48        //     //still dont move the first finger:
49        //     //go with moving 2nd finger:
50        //     int val2=(abs(x-x2)+abs(y-y2))+solve(word,ind+1,x1,y1,x,y);
51        //     mini = min({mini, val1, val2});
52        // } 
53           int x2=(f2-'A')/6;
54           int y2=(f2-'A') %6 ;
55            if(f1=='['){
56                int val1=solve(word,ind+1,word[ind],f2);
57                int val2=(abs(x-x2)+abs(y-y2))+solve(word,ind+1,f1,word[ind]);
58                   mini = min({mini, val1, val2});
59            }
60        
61        //ab donno pehle se lia hua hai kuch na kuch
62        //toh curr wla donno pe hi lekr dekhenge minimum kisme aa rha 
63        mini=min(mini,(abs(x-x1)+abs(y-y1))+solve(word,ind+1,word[ind],f2));
64        mini=min(mini,(abs(x-x2)+abs(y-y2))+solve(word,ind+1,f1,word[ind]));
65        return dp[ind][f1-'A'][f2-'A']= mini;
66    }
67    
68    int minimumDistance(string word) {
69           int n=word.size();
70           memset(dp,-1,sizeof(dp));
71           return solve(word,0,'[','[');
72    }
73};