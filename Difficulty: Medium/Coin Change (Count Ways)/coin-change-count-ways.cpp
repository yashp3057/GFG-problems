class Solution {
  public:
    int helper(vector<int>&arr, int sum, int idx,vector<vector<int>>&dp){
        
        if(idx==0){
          
         if(sum%arr[0]==0){
             return 1;
         }
                   return 0;
        }   
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        int take=0;
        if(sum>=arr[idx]){
            take=helper(arr,sum-arr[idx],idx,dp);
        }
        
        int nottake=helper(arr,sum,idx-1,dp);
        
        
        
    return dp[idx][sum]=take+nottake;
    
    
        
    }
    
    
    int count(vector<int>& coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(coins,sum,n-1,dp);
    }
};