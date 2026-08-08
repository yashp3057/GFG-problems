class Solution {
  public:
    int helper(vector<int>&price, int N,int idx,vector<vector<int>>&dp){
        
        
     if(idx==0){
         return price[0]*N; 
     }   
     
     if(dp[idx][N]!=-1){
         return dp[idx][N];
     }
        
        int nottake=0+helper(price,N,idx-1,dp);
        int pick=INT_MIN;
        int rodlength=idx+1;
        if(rodlength<=N){
            pick=price[idx]+helper(price,N-rodlength,idx,dp);
        }
        
        return dp[idx][N]=max(pick,nottake);
        
        
    }    
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(price,n,n-1,dp);
    }
};