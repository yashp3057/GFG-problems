class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int lastidx=-1;
        int maxi=0;
        vector<int>dp(n,1);
        vector<int>hash(n);
  
   for(int i=0; i<n; i++){
       hash[i]=i;
       for(int j=0; j<i; j++){
           
           if(arr[i]>arr[j] && dp[j]+1>dp[i]){
               
                dp[i]=1+dp[j];               
                hash[i]=j;
                
                
                
           }
           
           
           
       }
       if(dp[i]>maxi){
           maxi=dp[i];
           lastidx=i;
       }
   }
   
vector<int>ans;
ans.push_back(arr[lastidx]);

while(hash[lastidx]!=lastidx){
    lastidx=hash[lastidx];
    ans.push_back(arr[lastidx]);
    
    
}
reverse(ans.begin(),ans.end());
return ans;




    }
};