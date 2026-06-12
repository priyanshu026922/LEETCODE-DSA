1class TreeAncestor {
2public:
3   int rows;
4   int cols;
5   vector<vector<int>>ancestor;
6    TreeAncestor(int n, vector<int>& parent) {
7        rows=n;
8        cols=log2(n)+1;
9        ancestor.assign(rows,vector<int>(cols,-1));
10        for(int i=0;i<parent.size();i++){
11            ancestor[i][0]=parent[i];
12        }
13
14
15        for(int j=1;j<cols;j++){
16            for(int i=0;i<n;i++){
17               if(ancestor[i][j-1]>=0) ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
18            }
19        }
20    }
21    
22    int getKthAncestor(int node, int k) {
23        for(int i=0;i<32;i++){
24            if(k&(1<<i)){
25                node=ancestor[node][i];
26            }
27
28            if(node==-1){
29                 return -1;
30            }
31        }
32        return node;
33        
34    }
35};
36
37