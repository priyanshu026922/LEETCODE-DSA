1class Robot {
2public:
3    int ind=0;
4    bool move=false;
5    vector<vector<int>>grid;
6    Robot(int width, int height) {
7        // grid.assign(width,vector<int>(height));
8        
9        //bottom row(l->r):EAST
10        for(int i=0;i<width;i++){
11            grid.push_back({i,0,0});
12        }
13        //right row(d-->t):NORTH(1)
14        for(int j=1;j<height;j++){
15            grid.push_back({width-1,j,1});
16        }
17        //top row(r-->l):WEST(2)
18        for(int i=width-2;i>=0;i--){
19              grid.push_back({i,height-1,2});
20        }
21        //left row(t-->b):SOUTH(3)
22        for(int j=height-2;j>0;j--){
23            grid.push_back({0,j,3});
24        }
25        grid[0][2]=3;//make it south for idx=0(CORNER CASE)
26        //while retruning to {0,0}-->it goes back in SOUTH dir
27    }
28    
29    void step(int num) {
30       move=true;
31       ind=(ind+num)%grid.size();
32    }
33    
34    vector<int> getPos() {
35       return {grid[ind][0],grid[ind][1]};
36    }
37    
38    string getDir(){
39        if(!move){
40            return "East";
41        }
42
43        int dir=grid[ind][2];
44        if(dir==0){
45           return "East";
46        }
47        if(dir==1){
48           return "North";
49        }
50        if(dir==2){
51           return "West";
52        }
53        return "South";
54
55    }
56};
57
58/**
59 * Your Robot object will be instantiated and called as such:
60 * Robot* obj = new Robot(width, height);
61 * obj->step(num);
62 * vector<int> param_2 = obj->getPos();
63 * string param_3 = obj->getDir();
64 */