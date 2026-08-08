class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         
        int n=word1.length();
        int m=word2.length();

        //A string x is called almost equal to y if you can change at most one character in x to make it identical to y.


        // indices are sorted in ** ASCENDING ORDER **
        // Concatenating the characters at these indices in word1 in the same order 
        // :: results in a string that is almost equal to [ WORD2 ]

        vector<int>suff_match(n,0);
        int cnt=0;
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(j>=0&&word1[i]==word2[j]){
               cnt++;
               j--;
            }
            suff_match[i]=cnt; 
            i--;
        }

        // for(auto &it:suff_match){
        //     cout<<it<<" ";
        // }
     
        i=0;
        j=0;
        bool isTrue=true;
        vector<int>ans;
        while(i<n&&j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(isTrue&&i+1<n&&suff_match[i+1]>=m-j-1){
               ans.push_back(i);
               j++;
               isTrue=false;
            }
            i++;
        }

        return j==m?ans:vector<int>();
    }
};