1class Solution {
2public:
3    bool check(vector<vector<int>>& squares,double mid_y,double total){
4        double bot_area=0.00000;
5
6        for(auto &it:squares){
7            double y=it[1];
8            double l=it[2];
9
10            double bottom=y;
11            double top=y+l;
12
13            if(mid_y>=top){
14                bot_area+=l*l;
15            }else if(mid_y>bottom){
16                bot_area+=(mid_y-bottom)*l;
17            }
18        }
19        return bot_area>=total/2.0;
20    }
21    double separateSquares(vector<vector<int>>& squares) {
22       
23        double l=INT_MAX;
24        double h=INT_MIN;
25
26        double total=0.00000;
27        for(auto &it:squares){
28            double x=it[0];
29            double y=it[1];
30            double len=it[2];
31            total+=len*len;
32            l=min(l,y);
33            h=max(h,y+len);
34        }
35
36        double res=0.00000;
37        while(h-l>1e-5){
38            double mid_y=l+(h-l)/2;
39            res=mid_y;
40            if(check(squares,mid_y,total)){//bottom ares is greater
41                h=mid_y;
42            }else{
43                l=mid_y;
44            }
45        }
46        return res;
47    }
48};