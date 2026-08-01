class Solution {
  public:
  
   int helper(vector<int>&arr,int idx, int n,vector<int>&dp){
       
      
      if(idx>=n) return 0;  
       
   if(dp[idx]!=-1){
       return dp[idx];
   }
     int take=arr[idx]+helper(arr,idx+2, n, dp);       

       
      int nottake=0+helper(arr,idx+1,n, dp); 
       
  
  return dp[idx]=max(take,nottake);
  
   }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,-1);
        return helper(arr,0,n,dp);
    }
};