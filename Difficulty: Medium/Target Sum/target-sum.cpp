class Solution {
  public:
    int helper(vector<int>&arr,int target,int idx,vector<vector<int>>&dp){
        
     if(idx==0){
         
         
         if(target==0 || arr[idx]==target) return 1;
         
         if(target==0 && arr[idx]==0) return 2;
         
         return 0;
         
         
         
     }   
     if(dp[idx][target]!=-1) return dp[idx][target];
     
     int pick=0;
     if(target>=arr[idx]){
        pick= helper(arr,target-arr[idx],idx-1,dp);
     }
     
     int notpick=helper(arr,target,idx-1,dp);
             
        
    return dp[idx][target]=pick+notpick;    



    }
    
    
    
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int n=arr.size();
        int totalsum=0;
        for(int i=0; i<n; i++){
            totalsum+=arr[i];
        }
        
        if(target>totalsum) return 0;
        if((totalsum-target)%2!=0) return 0;
     
           int t=(totalsum-target)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
     
        
        return helper(arr,t,n-1,dp);
        
    }
};