1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int n=letters.size();
5        char ch='~';
6        for(int i=0;i<n;i++){
7            if(letters[i]>target){
8                ch=letters[i];
9                break;
10            }
11        }
12        if(ch=='~')return letters[0];
13        return ch;
14    }
15};