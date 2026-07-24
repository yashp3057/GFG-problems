class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prefixsum=0;
        unordered_map<int,int>mpp;
        int maxilen=0;
        for(int i=0; i<arr.size(); i++){
             prefixsum+=arr[i];
    
            if(prefixsum==0){
            maxilen=i+1;            
            }
            
            if(mpp.find(prefixsum)!=mpp.end()){
                maxilen=max(maxilen,i-mpp[prefixsum]);
            }
            else{
                mpp[prefixsum]=i;
            }
            
        }
        
        return maxilen;
        
    }
};