1class Solution {
2public:
3int n;
4vector<int>segMin;
5vector<int>segMax;
6vector<int>lazy;
7    
8    void propagate(int i,int l,int r){
9        if(lazy[i]!=0){
10            segMin[i]+=lazy[i];
11            segMax[i]+=lazy[i];
12
13            if(l!=r){
14                lazy[2*i+1]+=lazy[i];
15                lazy[2*i+2]+=lazy[i];
16            }
17            lazy[i]=0;
18        }
19    }
20
21
22    void updateRange(int start,int end,int i,int l,int r,int val){
23
24       propagate(i,l,r);
25
26       if(start>r||end<l){
27        return;
28       }
29       if(l>=start&&r<=end){
30          lazy[i]+=val;
31          propagate(i,l,r);
32          return;
33       }
34       int mid=(l+r)/2;
35       updateRange(start,end,2*i+1,l,mid,val);
36       updateRange(start,end,2*i+2,mid+1,r,val);
37       
38       segMin[i]=min(segMin[2*i+1],segMin[2*i+2]);
39       segMax[i]=max(segMax[2*i+1],segMax[2*i+2]);
40
41    }
42    int leftMostZero(int i,int l,int r){
43
44        propagate(i,l,r);
45
46        if(segMin[i]>0||segMax[i]<0){
47            return -1;
48        }
49        if(l==r)return r;
50
51        int mid=(l+r)/2;
52        int left=leftMostZero(2*i+1,l,mid);
53       
54        if(left!=-1){
55            return left;
56        }
57         return leftMostZero(2*i+2,mid+1,r);
58    }
59
60    int longestBalanced(vector<int>& nums) {
61        n=nums.size();
62        segMin.assign(4*n,0);
63        segMax.assign(4*n,0);
64        lazy.assign(4*n,0);
65
66        vector<int>cumSum(n,0);
67        unordered_map<int,int>mp;
68        int maxL=0;
69
70        for(int r=0;r<n;r++){
71            int val=(nums[r]%2==0)?1:-1;
72            int prev=-1;
73            if(mp.count(nums[r])){
74                prev=mp[nums[r]];
75            }
76
77            if(prev!=-1){
78                updateRange(0,prev,0,0,n-1,-val);
79                // for(int l=0;l<=prev;l++){
80                //     cumSum[l]-=val;//val-->-1 or1;
81                // }
82            }
83
84            updateRange(0,r,0,0,n-1,val);
85            // for(int l=0;l<=r;l++){
86            //     cumSum[l]+=val;
87            // }
88            // for(int l=0;l<=r;l++){
89            //     if(cumSum[l]==0){
90            //         maxL=max(maxL,r-l+1);
91            //         break;
92            //     }
93            // }
94            int l=leftMostZero(0,0,n-1);
95            if(l!=-1){
96                maxL=max(maxL,r-l+1);
97            }
98
99            mp[nums[r]]=r;
100        }
101
102        return maxL;
103    }
104};