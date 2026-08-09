class Solution {
  public:
    int helper(string s1,string s2,int n,int idx1,int idx2,vector<vector<int>>&dp){
      
      if(idx1==n || idx2==n) return 0;
      
      if(dp[idx1][idx2]!=-1){
          return dp[idx1][idx2];
      }
      
      
      if(s1[idx1]==s2[idx2]){
          return 1+helper(s1,s2,n,idx1+1,idx2+1,dp);
      }
      
      
      int move1=helper(s1,s2,n,idx1+1,idx2,dp);
      int move2=helper(s1,s2,n,idx1,idx2+1,dp);
      
      
      
      
    return dp[idx1][idx2]=max(move1,move2);  
  }
  
    int findMinInsertions(string &s) {
        // code here
     int n=s.size();
     
     string s2=s;
     
     reverse(s2.begin(),s2.end());
    
     vector<vector<int>>dp(n,vector<int>(n,-1));
     
     int g=helper(s,s2,n,0,0,dp);
     
     return n-g;
           
    }
};