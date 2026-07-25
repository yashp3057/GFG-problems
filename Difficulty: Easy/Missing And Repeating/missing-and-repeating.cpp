class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
    long long sum=0;
     long long sqrtsum=0;
     for(int i=0; i<arr.size(); i++){
         
         sum+=(long long)arr[i];
         sqrtsum+=(long long)arr[i]*(long long)arr[i];
         
         
     }
    
 long long totalsum=(1LL*n*(n+1))/2;
    long long totalsqrtsum=(1LL*(n)*(n+1)*(2*n+1))/6;
    
    long long x=sum-totalsum;
    long long y=sqrtsum-totalsqrtsum;
    
   y=y/x;
   
   long long ans1=(x+y)/2;
   long long ans2=ans1-x;
   
   return {ans1,ans2};
    
    
    
    }
};