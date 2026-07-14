class Disjointset {
public:
    vector<int> parents, size;

    Disjointset(int n) {
        parents.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parents[i] = i;
    }

    int finduparents(int node) {
        if (parents[node] == node)
            return node;

        return finduparents(parents[node]);
    }

    void unionbysize(int u, int v) {

        int up = finduparents(u);
        int vp = finduparents(v);

        if (up == vp)
            return;

        if (size[up] < size[vp]) {
            parents[up] = vp;
            size[vp] += size[up];
        } else {
            parents[vp] = up;
            size[up] += size[vp];
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;

        Disjointset ds(n * m);

        int count = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (auto it : operators) {

            int row = it[0];
            int col = it[1];

            if (vis[row][col] == 1) {
                ans.push_back(count);
                continue;
            }

            vis[row][col] = 1;
            count++;

            for (int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    if (vis[nr][nc] == 1) {

                        int nodeNo = row * m + col;
                        int adjNodeNo = nr * m + nc;

                        if (ds.finduparents(nodeNo) != ds.finduparents(adjNodeNo)) {
                            count--;
                            ds.unionbysize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};