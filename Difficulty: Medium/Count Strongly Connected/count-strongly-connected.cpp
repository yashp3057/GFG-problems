class Solution {
public:

    void revDfs(int node, vector<vector<int>>& reverseadj,
                vector<int>& vis) {

        vis[node] = 1;

        for (auto it : reverseadj[node]) {
            if (!vis[it]) {
                revDfs(it, reverseadj, vis);
            }
        }
    }

    void dfs(vector<vector<int>>& adj,
             vector<int>& vis,
             stack<int>& st,
             int start) {

        vis[start] = 1;

        for (auto it : adj[start]) {
            if (!vis[it]) {
                dfs(adj, vis, st, it);
            }
        }

        st.push(start);
    }

    int kosaraju(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, vis, st, i);
            }
        }

        // Step 2
        vector<vector<int>> reverseadj(V);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                reverseadj[it].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), 0);

        // Step 3
        int cnt = 0;

        while (!st.empty()) {

            int node = st.top();
            st.pop();

            if (!vis[node]) {
                cnt++;
                revDfs(node, reverseadj, vis);
            }
        }

        return cnt;
    }
};