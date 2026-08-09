class Solution {
  public:
      int helper(string s1,string s2,int n, int m,int idx1,int idx2,vector<vector<int>>&dp){
        
        
        
        if(idx1==n || idx2==m){
            
            return 0;
            
        }
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        
        if(s1[idx1]==s2[idx2]){
            return 1+helper(s1,s2,n,m,idx1+1,idx2+1,dp);
        }
        
        int move1=helper(s1,s2,n,m,idx1+1,idx2,dp);
        int move2=helper(s1,s2,n,m,idx1,idx2+1,dp);
        
        return dp[idx1][idx2]=max(move1,move2);
        
        
        
        
        
    }
  
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int lcs=helper(s1,s2,n,m,0,0,dp);
        
        return lcs+(n-lcs)+(m-lcs);
    }
};