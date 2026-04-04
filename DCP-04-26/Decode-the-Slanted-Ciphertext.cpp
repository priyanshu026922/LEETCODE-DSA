1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int n=encodedText.length();
5        int col=n/rows;
6        int x=0;
7        vector<vector<char>>vec(rows,vector<char>(col,' '));
8        for(int i=0;i<rows;i++){
9            for(int j=0;j<col;j++){
10                if(encodedText[x]==' '){
11                    vec[i][j]=' ';
12                }else{
13                    vec[i][j]=encodedText[x];
14                }
15                x++;
16            }
17        }
18
19        string ans="";
20            for(int j=0;j<col;j++){
21
22                int ind_i=0;
23                int ind_j=j;
24                while(ind_i<rows&&ind_j<col){
25                    if(vec[ind_i][ind_j]==' '){
26                        ans+=' ';
27                    }else{
28                        ans+=vec[ind_i][ind_j];
29                    }
30
31                    ind_i++;
32                    ind_j++;
33                }
34            //    cout<<vec[i][j];
35            }
36
37            int m=ans.length();
38            int i=m-1;
39            while(i>=0&&ans[i]==' '){
40                ans.pop_back();
41                i--;
42            }
43
44           
45        
46        return ans ;
47    }
48};