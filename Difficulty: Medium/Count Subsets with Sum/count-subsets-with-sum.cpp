class Solution {
  public:
  
  int helper(vector<int>&arr, int target, int idx, vector<vector<int>>&dp){
      
      
      if(idx==0){
          
          
          if(target==0 && arr[0]==0) return 2;
          if(target==0 || target==arr[0]) return 1;
          
          return 0;
      }
      if(dp[idx][target]!=-1) return dp[idx][target];
      
      int notpick=helper(arr,target,idx-1,dp);
      int pick=0;

      if(target>=arr[idx]){
          pick=helper(arr,target-arr[idx],idx-1,dp);
      }
      
      
      return dp[idx][target]=pick+notpick;
      
  }
  
  
  
  
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(arr,target,n-1,dp);
    }
};