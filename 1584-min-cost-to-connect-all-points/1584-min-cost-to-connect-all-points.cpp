class Solution {
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
                return true;
            }
            return false;
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<array<int, 3>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int totalCost = 0;
        int edgesCount = 0;

        for (auto& edge : edges) {
            if (dsu.unite(edge[1], edge[2])) {
                totalCost += edge[0];
                edgesCount++;
                if (edgesCount == n - 1) break;
            }
        }

        return totalCost;
    }
};