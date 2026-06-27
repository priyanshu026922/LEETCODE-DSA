1class LFUCache {
2private:
3  int cap;
4  int size=0;
5  unordered_map<int,list<vector<int>>::iterator>mp;//{key,value,freq}
6  map<int,list<vector<int>>>freq;
7public:
8    LFUCache(int capacity) {
9        cap=capacity;
10        size=0;
11    }
12    
13    int get(int key) {
14        if(mp.find(key)==mp.end()){
15            return -1;
16        }
17
18        auto &vec=(*(mp[key]));
19
20        int val=vec[1];
21        makeitMostRecent(key);
22
23
24        return val;
25    }
26
27
28    void makeitMostRecent(int key){
29        auto &vec=*(mp[key]);
30        int val=vec[1];
31        int f=vec[2];
32
33       
34
35        freq[f].erase(mp[key]);
36        if(freq[f].empty()){
37            freq.erase(f);
38        }
39
40        f++;
41        freq[f].push_front({key,val,f});
42
43        mp[key]=freq[f].begin();
44    }
45    
46    void put(int key, int value) {
47        if(mp.find(key)!=mp.end()){
48            auto &vec=(*(mp[key]));
49
50            vec[1]=value;
51            
52            makeitMostRecent(key);
53            return;
54            
55        }
56
57
58        if(size<cap){
59            size++;
60            freq[1].push_front({key,value,1});
61            mp[key]=freq[1].begin();//inserteed at the front of freq[1].begin
62            return;
63        }
64
65        auto &list=freq.begin()->second;
66
67        int key_del=list.back()[0];//key to delete
68
69        list.pop_back();
70        if(list.empty()){
71            freq.erase(freq.begin()->first);
72        }
73
74        //this represemts freq map with 1 counter
75        freq[1].push_front({key,value,1});
76        mp.erase(key_del);
77
78        mp[key]=freq[1].begin();
79    }
80};
81
82/**
83 * Your LFUCache object will be instantiated and called as such:
84 * LFUCache* obj = new LFUCache(capacity);
85 * int param_1 = obj->get(key);
86 * obj->put(key,value);
87 */