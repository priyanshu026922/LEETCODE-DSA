class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>m1;//vowel
        unordered_map<char,int>m2;//consonant
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                m1[s[i]]++;
            }
            else{
                m2[s[i]]++;
            }
        }

        int c1=0;
        int c2=0;
        for(auto &i:m1){
            c1=max(c1,i.second);
        }
         for(auto &i:m2){
            c2=max(c2,i.second);
        }
        return c1+c2;
    }
};