class Solution{
public:
vector<int>best;
int bestDiff=INT_MAX;
void check(vector<int>&curr){
    int maxi=*max_element(begin(curr),end(curr));
    int mini=*min_element(begin(curr),end(curr));
    if(maxi-mini<bestDiff){
        bestDiff=maxi-mini;
        best=curr;
    }
}

    void solve(int n,int k,int start,vector<int>&curr){
        if(k==1){
            if(n>=start){
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }
        
        for(int i=start;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                solve(n/i,k-1,i,curr);
                curr.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int>curr;
        solve(n,k,1,curr);
        return best;
    }
};