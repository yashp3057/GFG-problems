class Solution {
  public:
  int helper(int target,int idx, vector<int>&arr,int count,vector<vector<int>>&dp){
      
      
      if(target==0){
          return count;
      }
      if(idx==arr.size()){
          return INT_MAX;
      }
      if(dp[idx][target]!=-1) return dp[idx][target];
      
      int pick=INT_MAX;
      if(target>=arr[idx]){
          pick=helper(target-arr[idx],idx,arr,count+1,dp);
      }
      
      int notpick=helper(target,idx+1,arr,count,dp);
      
      
   return dp[idx][target]=min(pick,notpick);
      
  }
  
    int findMin(int n) {
        // code here
     vector<int>arr={10,5,2,1};
     vector<vector<int>>dp(4,vector<int>(n+1,-1));
     return helper(n,0,arr,0,dp);   
    }
};