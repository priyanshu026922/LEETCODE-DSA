1class Robot {
2public:
3    int n,m;
4    int ind=0;
5    bool move=false;
6    vector<vector<int>>grid;
7    Robot(int width, int height) {
8        // grid.assign(width,vector<int>(height));
9        n=width;
10        m=height;
11        //bottom row(l->r):EAST
12        for(int i=0;i<width;i++){
13            grid.push_back({i,0,0});
14        }
15        //right row(d-->t):NORTH(1)
16        for(int j=1;j<height;j++){
17            grid.push_back({width-1,j,1});
18        }
19        //top row(r-->l):WEST(2)
20        for(int i=width-2;i>=0;i--){
21              grid.push_back({i,height-1,2});
22        }
23        //left row(t-->b):SOUTH(3)
24        for(int j=height-2;j>0;j--){
25            grid.push_back({0,j,3});
26        }
27        grid[0][2]=3;//make it south for idx =0(CORNER CASE)
28    }
29    
30    void step(int num) {
31       move=true;
32       ind=(ind+num)%grid.size();
33    }
34    
35    vector<int> getPos() {
36       return {grid[ind][0],grid[ind][1]};
37    }
38    
39    string getDir(){
40        if(!move){
41            return "East";
42        }
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