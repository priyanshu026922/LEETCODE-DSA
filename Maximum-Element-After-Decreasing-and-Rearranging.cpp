1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        sort(begin(arr),end(arr));
5        long long  maxi=1;
6        long long  c=1;
7
8        arr[0]=1;
9
10        for(int i=1;i<arr.size();i++){
11            if(arr[i]-arr[i-1]<=1){
12                c=arr[i];
13            }else{
14                c++;
15                arr[i]=c;
16            }
17          
18            maxi=max(maxi,1LL*arr[i]);
19        }
20    //    cout<<arr.size()<<endl;
21    //    for(int i=0;i<arr.size();i++){
22    //         cout<<arr[i]<<" ";
23    //     }
24        
25
26        return (int)maxi;
27    }
28};