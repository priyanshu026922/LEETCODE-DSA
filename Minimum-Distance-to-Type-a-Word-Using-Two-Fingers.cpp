1class Solution {
2public:
3 int dp[301][7][7][7][7];
4    int solve(string word,int ind,int x1,int y1,int x2,int y2){
5        if(ind==word.length()){
6            return 0;
7        }
8        if(dp[ind][x1+1][y1+1][x2+1][y2+1]!=-1)return dp[ind][x1+1][y1+1][x2+1][y2+1];
9
10        int x=(word[ind]-'A')/6;
11        int y=(word[ind]-'A')%6;
12          
13        int mini=INT_MAX;
14        //NO FINGER IS MOVED TILL NOW:PICK ANY ONE:---
15        if((x1==-1&&y1==-1)&&(x2==-1&&y2==-1)){
16           mini= solve(word,ind+1,x,y,x2,y2);
17        } 
18        
19        //Second finger is not moved till now
20        if(x2==-1&&y2==-1){
21            //move the second finger
22            int val1=solve(word,ind+1,x1,y1,x,y);
23            //still dont move the second finger
24            //go with moving 1st finger 
25            int val2=(abs(x-x1)+abs(y-y1))+solve(word,ind+1,x,y,x2,y2);
26            mini = min({mini, val1, val2});
27        }
28
29         if(x1==-1&&y1==-1){
30            //move the first finger
31            int val1=solve(word,ind+1,x,y,x2,y2);
32            //still dont move the first finger:
33            //go with moving 2nd finger:
34            int val2=(abs(x-x2)+abs(y-y2))+solve(word,ind+1,x1,y1,x,y);
35            mini = min({mini, val1, val2});
36        } 
37        
38        mini=min(mini,(abs(x-x1)+abs(y-y1))+solve(word,ind+1,x,y,x2,y2));
39        mini=min(mini,(abs(x-x2)+abs(y-y2))+solve(word,ind+1,x1,y1,x,y));
40        return dp[ind][x1+1][y1+1][x2+1][y2+1]= mini;
41    }
42    
43    int minimumDistance(string word) {
44        int n=word.size();
45           memset(dp,-1,sizeof(dp));
46        return solve(word,0,-1,-1,-1,-1);
47    }
48};