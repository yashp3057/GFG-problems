class Solution {
  public:
  
    bool helper(vector<int>arr,int target,int idx,vector<vector<int>>&dp){
        
        if(idx==arr.size()) return false;
        
        if(target==0) return true;
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool pick=false;
        if(target>=arr[idx]){
            pick=helper(arr,target-arr[idx],idx+1,dp);
        }
        
        bool notpick=helper(arr,target,idx+1,dp);
        
        return dp[idx][target]=pick || notpick;
        
        
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int totalsum=0;
        int n=arr.size();
        
        for(int i=0; i<arr.size(); i++){
            totalsum+=arr[i];
        }
        
        if(totalsum % 2 !=0){
            return false;
        }
        int sum=totalsum/2;
          vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       
            return helper(arr,totalsum/2,0,dp);
      
        
        
    }
};