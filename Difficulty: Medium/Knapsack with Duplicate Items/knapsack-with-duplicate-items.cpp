class Solution {
  public:
    int helper(vector<int>&val, vector<int>&wt,int capacity,int idx,vector<vector<int>>&dp){
        
        
        if(idx==0){
            
            
            return (capacity/wt[idx])*val[0];
            
        }
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        
        
        int take=0;
        if(wt[idx]<=capacity){
        
        take=val[idx]+helper(val,wt,capacity-wt[idx],idx,dp);    
            
        }
        int nottake=0+helper(val,wt,capacity,idx-1,dp);
        
    return dp[idx][capacity]=max(take,nottake);    
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return helper(val,wt,capacity,n-1,dp);
    }
};