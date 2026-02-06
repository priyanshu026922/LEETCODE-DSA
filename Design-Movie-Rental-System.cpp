1class MovieRentingSystem {
2public:
3
4unordered_map<int,set<pair<int,int>>>available;
5set<tuple<int,int,int>>rented;
6map<pair<int,int>,int>mp;
7
8    MovieRentingSystem(int n, vector<vector<int>>& entries){
9         
10          for(auto it:entries){
11            int x=it[0];
12            int y=it[1];
13            int z=it[2];
14            available[y].insert({z,x});//movie---->{price,shop}
15            mp[{x,y}]=z;
16          }
17    }
18    
19    vector<int> search(int movie){
20       vector<int>ans;
21       int cnt=0;
22       if(available.count(movie)>0){
23            for(auto &it:available[movie]){
24                cnt++;
25                ans.push_back(it.second);
26                if(cnt==5)break;
27            }
28       }
29       return ans;
30    }
31    
32    void rent(int shop, int movie) {
33       int val=mp[{shop,movie}];
34       rented.insert({val,shop,movie});
35       available[movie].erase({val,shop});
36    }
37    
38    void drop(int shop, int movie) {
39         int val=mp[{shop,movie}];
40         available[movie].insert({val,shop});
41         rented.erase({val,shop,movie});
42    }
43    
44    vector<vector<int>> report() {
45         vector<vector<int>>res;
46         int cnt=0;
47         for(auto &it:rented){//price..shop..movie
48           res.push_back({ get<1>(it), get<2>(it) });
49             cnt++;
50             if(cnt==5)break;
51         } 
52         return res;
53    }
54};
55
56/**
57 * Your MovieRentingSystem object will be instantiated and called as such:
58 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
59 * vector<int> param_1 = obj->search(movie);
60 * obj->rent(shop,movie);
61 * obj->drop(shop,movie);
62 * vector<vector<int>> param_4 = obj->report();
63 */