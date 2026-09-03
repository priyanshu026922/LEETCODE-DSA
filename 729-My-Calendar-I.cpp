class MyCalendar {
public:
    vector<vector<int>>vec;
    MyCalendar() {
       
    }
    
    bool book(int startTime, int endTime) {
       int n=vec.size();
       sort(begin(vec),end(vec));
        for(int i=0;i<n;i++){
            int x=vec[i][0];
            int y=vec[i][1];

            if(startTime<y&& endTime>x){
                return false;
            }
        }
       vec.push_back({startTime,endTime});

       return true;
    }
};

