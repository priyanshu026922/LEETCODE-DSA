1class NumArray {
2public:
3vector<int>vec;
4vector<int>segTree;
5int n;
6    NumArray(vector<int>& nums) {
7        n=nums.size();
8        vec=nums;
9        segTree.resize(4*n);
10        solve(0,0,n-1);
11    }
12
13    void updateQuery(int i,int l,int r,int ind,int val){
14        if(l==r){
15            segTree[i]=val;
16            return;
17        }
18        int mid=(l+r)/2;
19        if(ind<=mid){
20            updateQuery(2*i+1,l,mid,ind,val);
21        }else{
22            updateQuery(2*i+2,mid+1,r,ind,val);
23        }
24        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
25    }
26    void update(int index, int val) {
27        vec[index]=val;
28        updateQuery(0,0,n-1,index,val);
29    }
30
31     //COrRECT
32    int querySum(int start,int end,int ind,int l,int r,vector<int>&segTree){
33        if(r<start||l>end)return 0;
34        if(l>=start&&r<=end)return segTree[ind];
35        int mid=(l+r)/2;
36
37        return querySum(start,end,2*ind+1,l,mid,segTree)+querySum(start,end,2*ind+2,mid+1,r,segTree);
38    }
39
40    //CORRECT
41    void solve(int i,int l,int r){
42      if(l==r){
43        segTree[i]=vec[r];
44        return;
45      }
46
47      int mid=(l+r)/2;
48      solve(2*i+1,l,mid);
49      solve(2*i+2,mid+1,r);
50      segTree[i]=segTree[2*i+1]+segTree[2*i+2];
51    }
52
53
54    int sumRange(int left, int right) {
55        return querySum(left,right,0,0,n-1,segTree);
56    }
57};
58
59/**
60 * Your NumArray object will be instantiated and called as such:
61 * NumArray* obj = new NumArray(nums);
62 * obj->update(index,val);
63 * int param_2 = obj->sumRange(left,right);
64 */