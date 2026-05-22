1class StockSpanner {
2public:
3    stack<pair<int,int>>s;
4    int index;
5    StockSpanner() {
6        index=-1;
7    }
8    
9    int next(int price) {
10       index++;
11       while(!s.empty()&&s.top().first<=price){
12        s.pop();
13       }
14       int ans=index-(s.empty()?-1:s.top().second);
15       s.push({price,index});
16       return ans;
17    }
18};
19
20/**
21 * Your StockSpanner object will be instantiated and called as such:
22 * StockSpanner* obj = new StockSpanner();
23 * int param_1 = obj->next(price);
24 */