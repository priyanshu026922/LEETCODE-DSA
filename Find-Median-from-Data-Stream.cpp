class MedianFinder {
public:
priority_queue<int>p;
priority_queue<int,vector<int>,greater<int>>q;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p.empty()||num<p.top()){
            p.push(num);
        }
       else{
          q.push(num);
        }

       if(q.size()>p.size()){
        p.push(q.top());
        q.pop();
       }else if(p.size()>q.size()+1){
        q.push(p.top());
        p.pop();
       }
    }
    
    double findMedian() {
         if((p.size()+q.size())%2==0)return (p.top()+q.top())/2.0;
         return p.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */