class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
vector<vector<int>> adj(V);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        
        
        vector<int>dist(V,INT_MAX);
        
        dist[src]=0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            
            int top=q.front();
            q.pop();
            
            for(auto it: adj[top]){
                
                if((dist[top]+1)<dist[it]){
                    dist[it]=dist[top]+1;
                    q.push(it);
                }
                
                
                
            }
            
            
            
            
        }
        
        if(dist[dest]==INT_MAX) return -1;
        return dist[dest];
        
    }
};
