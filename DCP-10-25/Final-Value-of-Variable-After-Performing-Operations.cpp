class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n=operations.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string s=operations[i];
            char ch1=s[0];
            char ch2=s[2];
            if(ch1=='-'||ch2=='-'){
                ans--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};