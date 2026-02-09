1class Solution {
2public:
3    int largestMagicSquare(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6
7        vector<vector<int>>rows(n,vector<int>(m,0));
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                rows[i][j]=grid[i][j]+(j>0?rows[i][j-1]:0);
11            }
12        }
13        vector<vector<int>>cols(n,vector<int>(m,0));
14        for(int j=0;j<m;j++){
15            for(int i=0;i<n;i++){
16                cols[i][j]=grid[i][j]+(i>0?cols[i-1][j]:0);
17            }
18        }
19
20
21        int maxi=1;
22        for(int i=0;i<n;i++){
23            for(int j=0;j<m;j++){
24
25                for(int k=1;i+k-1<n&&j+k-1<m;k++){//side of k length
26                    int x=i+k-1;
27                    int y=j+k-1;
28                  
29
30                   int tarSum=rows[i][y]-(j>0?rows[i][j-1]:0);
31                   bool same=true;
32
33                   for(int z=i+1;z<=x;z++){
34                      int rowSum=rows[z][y]-(j>0?rows[z][j-1]:0);
35                      if(rowSum!=tarSum){
36                        same=false;
37                        break;
38                      }
39                   }
40                   if(!same)continue;
41                   
42                     tarSum=cols[x][j]-(i>0?cols[i-1][j]:0);
43                    for(int z=j+1;z<=y;z++){
44                      int colSum=cols[x][z]-(i>0?cols[i-1][z]:0);
45                      if(colSum!=tarSum){
46                        same=false;
47                        break;
48                      }
49                   }
50                   if(!same)continue;
51
52                   int s=0,s1=0;
53                   for(int z=0;z<k;z++){
54                        s+=grid[i+z][j+z];
55                        s1+=grid[i+z][y-z];
56                   }
57                   if(s!=tarSum||s1!=tarSum)continue;
58                   maxi=max(maxi,k);
59
60                }
61            }
62        }
63return maxi;
64    }
65};