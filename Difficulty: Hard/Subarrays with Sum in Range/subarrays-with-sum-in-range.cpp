class Solution {
  public:
    
    int helper(vector<int>&arr, int target){
        
    int l=0;
    int r=0;
    int n=arr.size();
    int sum=0;
    int count=0;
    while(r<n){
        sum+=arr[r];
        while(sum>target){
            sum-=arr[l];
            l++;
        }
        
        count+=(r-l+1);
        r++;
        
        
        
        
        
        
        
    }
        
        
        
        
        
       return count; 
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
       
       return helper(arr,r)-helper(arr,l-1);
       
        
    }
};