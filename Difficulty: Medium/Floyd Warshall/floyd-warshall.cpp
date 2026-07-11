class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {

        int n = dist.size();

        // Try every node as an intermediate node
        for (int via = 0; via < n; via++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    // Update only if both paths exist
                    if (dist[i][via] != 1e8 && dist[via][j] != 1e8) {

                        dist[i][j] = min(dist[i][j],
                                         dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};