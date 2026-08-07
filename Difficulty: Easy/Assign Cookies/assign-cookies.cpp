class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        
        
        
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        
        int i=0; 
        int j=0;
        int count=0;
        
        while(i<greed.size() && j<cookie.size()){
            
            
            if(cookie[j] >= greed[i]){
                j++;
                i++;
                count++;
            }
            
            else{
                j++;
            }
            
             
        }
        
        return count;
        
        
        
        
    }
};