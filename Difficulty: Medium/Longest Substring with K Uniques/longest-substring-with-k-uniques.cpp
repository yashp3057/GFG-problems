class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        int l=0;
        int r=0;
        int maxlen=-1;
        unordered_map<char,int>mpp;
        
        while(r<s.size()){
            
            mpp[s[r]]++;
            
            
            while(mpp.size()>k){
                
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            
            if(mpp.size()==k){
            maxlen=max(maxlen,r-l+1);
            
            
           
            
            
            }
            r++;
            
        }
        
        
        return maxlen;
        
    }
};