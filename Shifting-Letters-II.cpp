class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n,0);
        for(int i=0;i<shifts.size();i++){
                int x=shifts[i][0];
                int y=shifts[i][1];
                int dir=shifts[i][2];
                
                if(dir==1){
                    diff[x]++;
                if(y+1<n) diff[y+1]--;
                }else{
                    diff[x]--;
                    if(y+1<n)diff[y+1]++;
                }
             // cout<<s<<endl;
        }
          

        vector<int>v(n,0);
        v[0]=diff[0];
        for(int i=1;i<n;i++){
           v[i]=v[i-1]+diff[i];
        }


        for(int i=0;i<n;i++){
            int shift=v[i]%26;
            if(shift<0){
                shift+=26;
            }

            s[i]=(((s[i]-'a')+shift)%26)+'a';
            // if(v[i]>=0){
            //         s[i]=((s[i]-'a')+v[i]%26)%26+'a';
            // }else{
            //      s[i]=((26+s[i]-'a')-abs(v[i]%26))%26+'a'; 
            // }
        }
        
        return s;
    }
};



