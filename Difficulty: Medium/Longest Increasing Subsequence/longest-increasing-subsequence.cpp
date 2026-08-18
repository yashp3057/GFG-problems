class Solution {
  public:
    int helper(vector<int>& arr, int prev, int idx,int n,vector<vector<int>>&dp){
        
        
        if(idx==n) return 0; 
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int nottake=0+helper(arr,prev,idx+1,n,dp);
        
        int take=0;
        if(prev==-1 || arr[idx]>arr[prev]){
            take=1+helper(arr,idx,idx+1,n,dp);
        }
        
    
        return dp[idx][prev+1]= max(take,nottake);
        
        
    }
    
    
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(arr,-1,0,n,dp);
    }
};