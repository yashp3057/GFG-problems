class Solution {
  public:
    int helper(string s1, string s2,int i,int j,vector<vector<int>>&dp){
        
        
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
       if(s1[i]==s2[j]){
      
      
      int take=helper(s1,s2,i-1,j-1,dp);
      
      int nottake=helper(s1,s2,i-1,j,dp);
      
      return dp[i][j]=take+nottake;
      
       } 
       
        
      return dp[i][j]=helper(s1,s2,i-1,j,dp);  
        
        
    }
    int subseqCount(string &txt, string &pat) {
        // code here
        int n=txt.size();
        int m=pat.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(txt,pat,n-1,m-1,dp);
    }
};