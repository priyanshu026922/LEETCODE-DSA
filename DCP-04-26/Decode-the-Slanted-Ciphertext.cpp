1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int n=encodedText.length();
5        int col=n/rows;
6        int x=0;
7        string ans="";
8        for(int i=0;i<col;i++){
9            for(int j=i;j<n;j+=(col+1)){
10                ans+=encodedText[j];
11            }
12        } 
13
14            int m=ans.length();
15            int i=m-1;
16            while(i>=0&&ans[i]==' '){
17                ans.pop_back();
18                i--;
19            }
20        return ans ;
21    }
22};