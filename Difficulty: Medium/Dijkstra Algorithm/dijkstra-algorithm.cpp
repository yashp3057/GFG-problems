class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        // Build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});   // Remove if graph is directed
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            int di = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(di > dist[node]) continue;

            for(auto it : adj[node]){

                int edgeNode = it.first;
                int edgeDist = it.second;

                if(di + edgeDist < dist[edgeNode]){

                    dist[edgeNode] = di + edgeDist;
                    pq.push({dist[edgeNode], edgeNode});
                }
            }
        }

        return dist;
    }
};