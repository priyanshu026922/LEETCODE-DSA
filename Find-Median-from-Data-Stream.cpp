1class MedianFinder {
2    priority_queue<int>pq1;
3priority_queue<int,vector<int>,greater<int>>pq2;
4public:
5
6    MedianFinder(){} 
7
8
9    
10    void addNum(int num) {
11
12        int n=pq1.size();
13        int m=pq2.size();
14        if(pq1.empty()||num<pq1.top()){
15            pq1.push(num);
16        }else{
17          pq2.push(num); 
18        } 
19
20
21        if(pq2.size()>pq1.size()){
22             pq1.push(pq2.top());
23             pq2.pop();
24        }else if(pq1.size()>pq2.size()+1){
25            pq2.push(pq1.top());
26            pq1.pop();
27        }
28
29    }
30    
31    double findMedian() {
32        int n=pq1.size();
33        int m=pq2.size();
34        double val=-1;
35        if((n+m)%2!=0){
36           return pq1.top();
37        }
38
39       val=((double)pq1.top()+(double)pq2.top())/2.0;
40        return val;
41    }
42};
43
44/**
45 * Your MedianFinder object will be instantiated and called as such:
46 * MedianFinder* obj = new MedianFinder();
47 * obj->addNum(num);
48 * double param_2 = obj->findMedian();
49 */