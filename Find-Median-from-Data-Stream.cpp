1class MedianFinder {
2public:
3priority_queue<int>pq1;
4priority_queue<int,vector<int>,greater<int>>pq2;
5    MedianFinder() {
6        
7    }
8    
9    void addNum(int num) {
10        if(pq1.empty()||num<=pq1.top()){
11            pq1.push(num);
12        }else{
13            pq2.push(num);
14        }
15
16        //hmesha x+1 and x sieze maintian kreke chleenge
17        if(pq1.size()>1+pq2.size()){
18            int x=pq1.top();
19            pq1.pop();
20            pq2.push(x);
21        }
22
23        if(pq2.size()>pq1.size()){
24             int x=pq2.top();
25            pq2.pop();
26            pq1.push(x);
27        }
28    }
29    
30    double findMedian() {
31        int n=pq1.size();
32        int m=pq2.size();
33        if((n+m)%2==0){
34            double ans=(double)pq1.top()+(double)pq2.top();
35            return ans/2.0;
36        }
37        return (double)pq1.top();
38    }
39};
40
41/**
42 * Your MedianFinder object will be instantiated and called as such:
43 * MedianFinder* obj = new MedianFinder();
44 * obj->addNum(num);
45 * double param_2 = obj->findMedian();
46 */