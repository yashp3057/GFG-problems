class Solution {
  public:
    int helper(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        
        
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]) return dp[i][j]=helper(s1,s2,i-1,j-1,dp);
        
        int insert=1+helper(s1,s2,i,j-1,dp);
        int remov=1+helper(s1,s2,i-1,j,dp);
        int replace=1+helper(s1,s2,i-1,j-1,dp);
        
        
        
        return dp[i][j]=min({insert,remov,replace});
        
        
    
        
        
    }
    
    
    
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s1,s2,n-1,m-1,dp);
    }
};