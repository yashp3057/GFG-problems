class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        
        int half=n/2;
        vector<int>v1;
        vector<int>v2;
        
        for(int i=0; i<half; i++){
            v1.push_back(arr[i]);
        }
        
        for(int j=half; j<n; j++){
            v2.push_back(arr[j]);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        int ans=0;
        int j=0;
        
        
        for(int i=0; i<half; i++){
            
            while(j<half && v1[i]>=5*v2[j]){
                j++;
            }
            ans+=j;
            
        }
        
        return ans;
    }
};