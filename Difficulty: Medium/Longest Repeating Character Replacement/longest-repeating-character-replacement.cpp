class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int l=0;
        int r=0;
        int maxlen=0;
        int n=s.size();
        int maxfreq=0;
   
        vector<int>freq(26,0);
        
        while(r<n){
            
            freq[s[r]-'A']++;
            
            maxfreq=max(maxfreq,freq[s[r]-'A']);
            
            
            while((r-l+1)-maxfreq>k){
                
                freq[s[l]-'A']--;
                l++;
                maxfreq=0;
                for(int i=0; i<freq.size(); i++){
                    maxfreq=max(maxfreq,freq[i]);
                }
                
            }
            
            if((r-l+1)-maxfreq<=k){
                
            
               maxlen=max(maxlen,r-l+1);
               r++;
                
            }
            
            
            
            
            
            
            
            
            
            
            
            
        }
        
        
        
        
        return maxlen;
    }
};