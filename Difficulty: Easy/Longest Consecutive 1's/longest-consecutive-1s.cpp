class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        
        // conver into string

        string ans="";
        while(n>0){
            
         char ch=(n%2)+'0';
         ans+=ch;
         n=n/2;
         
            
            
            
        }
        
        reverse(ans.begin(),ans.end());
        int l=0;
        int r=0;
        int maxlen=0;
        while(r<ans.size()){
            
            if(ans[r]=='1'){
                
                l=r;
                
                while(r<ans.size() && ans[r]=='1'){
                    r++;
                }
                
                maxlen=max(maxlen,r-l);
                
                
                
                
                
            }
            
            else{
                r++;
            }
            
            
        }
        
       return maxlen; 
        
        
        
    }
};
