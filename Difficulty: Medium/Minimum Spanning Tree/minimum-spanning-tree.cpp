class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto it: edges){
            
            int u=it[0];
            int v=it[1];
            int w=it[2];
           
           adj[u].push_back({v,w});
           adj[v].push_back({u,w});
           
        }
        
        vector<int>vis(V,0);
        
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  int sum=0;
  pq.push({0,0});
        
        while(!pq.empty()){
            
            
        int wt=pq.top().first;    
        int node=pq.top().second;
        
        pq.pop();
        
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        
        for(auto it:adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;
            if(vis[adjnode]==0){
                pq.push({adjwt,adjnode});
            }
        }
        
            
            
            
        }
        return sum;
    } 
}; 