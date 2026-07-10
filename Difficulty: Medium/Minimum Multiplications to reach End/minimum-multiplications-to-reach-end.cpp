class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        
        vector<int>step(1000,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,start});
        step[start]=0;
        while(!q.empty()){
            
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
              if(node==end) return steps;
            for(auto it:arr){
                int nel=(it*node)%1000;
                
                
                if(steps+1<step[nel]){
                    step[nel]=steps+1;
                  
                    q.push({steps+1,nel});
                    
                }
                
                
                
            }
            
            
            
            
        }
        return -1;
        
    }
};